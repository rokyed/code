/// @file Slotsets are used to load and organize texture-slots chunk wise.
///

#include "inexor/shared/filesystem.h"
#include "inexor/texture/slotregistry.h"

namespace inexor {
namespace texture {

    static slotregistry *currentslotreg = NULL;

    /// Set the current slot registry to the specific given one and (atm) DELETES the current one (at this stage we dont further need it).
    /// @warning not threadsafe.
    void switchcurslotreg()
    {
        delete currentslotreg;
        currentslotreg = new slotregistry();
    }

    /// Receive the current maps texture slot stack.
    slotregistry *getcurslotreg()
    {
        if(!currentslotreg) switchcurslotreg();
        return currentslotreg;
    }

    struct jsontextype {
        const char *name;
        int type;
    } jsontextypes[TEX_NUM] = {
        { "diffuse", TEX_DIFFUSE },
        { "other", TEX_UNKNOWN },
        { "decal", TEX_DECAL },
        { "normal", TEX_NORMAL },
        { "glow", TEX_GLOW },
        { "spec", TEX_SPEC },
        { "depth", TEX_DEPTH },
        { "envmap", TEX_ENVMAP }
    }; //todo: int gettype() function and const char *getjsontex to not iterate over TEX_NUM

    /// Add all texture entries to the Slottexture.
    /// @return true on success.
    bool addimagefiles(Slot &s, JSON *j)
    {
        loopi(TEX_NUM) //check for all 8 kind of textures
        {
            JSON *sub = j->getchild(jsontextypes[i].name);
            //if(i == TEX_DIFFUSE && !sub) return false; else // no diffuse texture: other stuff wont work?
            if(!sub) continue;
            char *name = sub->valuestring;
            if(!name) continue;
            s.texmask |= 1 << i;
            s.addtexture(i, name, parentdir(j->currentfile));
        }
        return s.sts.length() != 0;
    }

    /// Add all size/rotation/offset/scroll modifiers.
    void addvslotparams(Slot &s, JSON *j)
    {
        JSON *scale = j->getchild("scale"), *rot = j->getchild("rotation"), *offset = j->getchild("offset"),
        *scroll = j->getchild("scroll"), *alpha = j->getchild("alpha"), *color = j->getchild("color");

        VSlot &vs = *getcurslotreg()->addvslot(s);
        vs.reset();
        vs.rotation = rot ? clamp(rot->valueint, 0, 5) : 0;
        vs.scale = scale ? scale->valuefloat : 1;

        if(offset)
        {
            JSON *x = offset->getchild("x"), *y = offset->getchild("y");
            vs.offset = ivec2(x ? max(x->valueint, 0) : 0, y ? max(y->valueint, 0) : 0);
        }

        if(scroll)
        {
            JSON *x = scroll->getchild("x"), *y = scroll->getchild("y");
            vs.scroll = vec2(x ? x->valuefloat / 1000.0f : 0, y ? y->valuefloat / 1000.0f : 0);
        }

        if(alpha)
        {
            JSON *front = alpha->getchild("front"), *back = alpha->getchild("back");
            vs.alphafront = front ? clamp(front->valuefloat, 0.0f, 1.0f) : 0.5f; //todo
            vs.alphaback = back ? clamp(back->valuefloat, 0.0f, 1.0f) : 0;
        }

        if(color)
        {
            JSON *red = color->getchild("red"), *green = color->getchild("green"), *blue = color->getchild("blue");
            float r = red ? clamp(red->valuefloat, 0.0f, 1.0f) : 0.0f;
            float g = green ? clamp(green->valuefloat, 0.0f, 1.0f) : 0.0f;
            float b = blue ? clamp(blue->valuefloat, 0.0f, 1.0f) : 0.0f;

            vs.colorscale = vec(r, g, b);
        }

        propagatevslot(&vs, (1 << VSLOT_NUM) - 1); // apply vslot changes
    }

    void slotregistry::addslot(JSON *j)
    {
        if(!j || slots.length() >= 0x10000) return;

        Slot *s = new Slot(slots.length());
        s->loaded = false;

        if(!addimagefiles(*s, j)) return; // no textures found

        JSON *shad = j->getchild("shader");
        setslotshader(*s, shad); // TODO: multithread

        addvslotparams(*s, j); // other parameters
    }

    void slotregistry::addslot(const char *filename)
    {
        if(!filename || !*filename) return;
        JSON *j = loadjson(filename);
        if(!j) {
            conoutf("could not load texture slot definition %s", filename);
            return;
        }

        addslot(j);
        delete j;
    }
    
    // helper for addvslot, currently only used when in editmode new vslots get created.
    inline bool slotregistry::vslotlimitreached() const
    {
        return vslots.length() >= MAXVSLOTAMOUNT;
    }

    // helper for addvslot
    VSlot *slotregistry::clonevslot(const VSlot &src, const VSlot &delta)
    {
        VSlot *dst = vslots.add(new VSlot(src.slot, vslots.length()));
        dst->changed = src.changed | delta.changed;
        propagatevslot(*dst, src, ((1 << VSLOT_NUM) - 1) & ~delta.changed);
        propagatevslot(*dst, delta, delta.changed, true);
        return dst;
    }

    //VARP(autocompactvslots, 0, 256, 0x10000); //TODO: autocompact is not effectively used anywhere (neither in sauerbraten).. BUG!
    VSlot *slotregistry::addvslot(const VSlot &src, const VSlot &delta)
    {
        VSlot *exists = src.slot->findvariant(src, delta);
        if(exists) return exists;
        if(vslotlimitreached()) // (autocompactvslots && ++clonedvslots >= autocompactvslots))
        {
            compactvslots();
            allchanged();
            if(vslotlimitreached()) return NULL;
        }
        return clonevslot(src, delta);
    }

    VSlot *slotregistry::addvslot(Slot &owner)
    {
        int offset = 0;
        loopvrev(slots) if(slots[i]->variants) { offset = slots[i]->variants->index + 1; break; }
        for(int i = offset; i < vslots.length(); i++) if(!vslots[i]->changed) return owner.setvariantchain(vslots[i]);
        return vslots.add(new VSlot(&owner, vslots.length()));
    }

    void slotregistry::load()
    {
        loopv(slots)
        {
            slots[i]->load(true, false);
        }
    }

    void slotregistry::linkshaders()
    {
        loopv(slots) if(slots[i]->loaded) linkslotshader(*slots[i]);
        loopv(vslots) if(vslots[i]->linked) linkvslotshader(*vslots[i]);
        loopi((MATF_VOLUME | MATF_INDEX) + 1) if(materialslots[i].loaded)
        {
            linkslotshader(materialslots[i]);
            linkvslotshader(materialslots[i]);
        }
    }

    /// Creates a slotregistry with all textures from a "textures" child of given JSON structure.
    /// @sideeffects allocates memory for a new slotset
    slotregistry::slotregistry(JSON *parent)
    {
        if(!parent) return;
        JSON *j = parent->getchild("textures");
        if(!j) {
            conoutf("no child entry found for textures");
            return;
        }

        loopi(j->numchilds())
        {
            const char *name = j->getchildstring(i);
            defformatstring(fn, "%s", name);
            if(name[0] != '/') formatstring(fn, "%s", makerelpath(parentdir(j->currentfile), name)); //relative path to current folder
            addslot(fn);
        }
    }

    slotregistry::slotregistry(const char *name, bool load)
    {
        string fname;
        filesystem::getmedianame(fname, MAXSTRLEN, name, DIR_TEXTURE);
        JSON *j = loadjson(fname);
        if(!j) { conoutf("could not load %s slotset", name); return; }
        slotregistry *t = new slotregistry(j);

        delete j;

        if(load) t->load();
    }

    void slotregistry::echo()
    {
        int numtextures = 0;
        int slotvslots = 0;
        loopv(slots) {
            int numvslots = 0;
            VSlot *vs = slots[i]->variants;
            for(numvslots = 0; vs; vs = vs->next) numvslots++;
            conoutf("## Slot %d (deriving VSlots: %d)", i, numvslots);
            slotvslots += numvslots;

            loopvk(slots[i]->sts) conoutf("texture %d: %s", k, slots[i]->sts[k].name);
            numtextures += slots[i]->sts.length();
        }
        conoutf("slotregistry has %d slots with %d textures", slots.length(), numtextures);
    }

    void slotregistry::texturereset(int first, int num)
    {
        resetslotshader(); //TODO
        first = clamp(first, 0, slots.length());
        if(!num) num = slots.length() - first;
        num = clamp(num, 0, slots.length() - first);

        loopi(num)
        {
            Slot *s = slots.remove(first);
            for(VSlot *vs = s->variants; vs; vs = vs->next) vs->slot = &dummyslot;
            delete s;
        }

        while(vslots.length())
        {
            VSlot *vs = vslots.last();
            if(vs->slot != &dummyslot || vs->changed) break;
            delete vslots.pop();
        }
    }
    ICOMMAND(texturereset, "ii", (int *first, int *last), getcurslotreg()->texturereset(*first, *last));

    void slotregistry::materialreset()
    {
        loopi((MATF_VOLUME | MATF_INDEX) + 1) materialslots[i].reset();
    }
    ICOMMAND(materialreset, "", (), getcurslotreg()->materialreset());

    void slotregistry::serializevslot(vector<uchar> &buf, int index)
    {
        if(vslots.inrange(index)) vslots[index]->serialize(buf);
        else buf.put(0xFF);
    }

    void slotregistry::savetoogz(stream *f, int numvslots)
    {
        if(vslots.empty()) return;
        int *prev = new int[numvslots];
        memset(prev, -1, numvslots*sizeof(int));
        loopi(numvslots)
        {
            VSlot *vs = vslots[i];
            if(vs->changed) continue;
            for(;;)
            {
                VSlot *cur = vs;
                do vs = vs->next; while(vs && vs->index >= numvslots);
                if(!vs) break;
                prev[vs->index] = cur->index;
            }
        }
        int lastroot = 0;
        loopi(numvslots)
        {
            VSlot &vs = *vslots[i];
            if(!vs.changed) continue;
            if(lastroot < i) f->putlil<int>(-(i - lastroot));
            vs.savetoogz(f, prev[i]);
            lastroot = i + 1;
        }
        if(lastroot < numvslots) f->putlil<int>(-(numvslots - lastroot));
        delete[] prev;
    }

    void slotregistry::parsefromogz(stream *f, int numvslots)
    {
        int *prev = new int[numvslots];
        memset(prev, -1, numvslots*sizeof(int));
        while(numvslots > 0)
        {
            int changed = f->getlil<int>();
            if(changed < 0)
            {
                loopi(-changed) vslots.add(new VSlot(NULL, vslots.length()));
                numvslots += changed;
            }
            else
            {
                prev[vslots.length()] = f->getlil<int>();
                VSlot *vs = vslots.add(new VSlot(NULL, vslots.length()));
                vs->parsefromogz(f, changed);
                numvslots--;
            }
        }
        loopv(vslots) if(vslots.inrange(prev[i])) vslots[prev[i]]->next = vslots[i];
        delete[] prev;
    }

    /// Echo all texture mapslots loaded.
    void debugslots()
    {
        getcurslotreg()->echo();
    }
    COMMAND(debugslots, "");

}     // namespace texture
}     // namespace inexor

using namespace inexor::texture;

/// Returns how many texture slots this map currently has, usefule e.g. for the texture browser.
int numcurslots()
{
    return getcurslotreg()->slots.length();
}
ICOMMAND(getslotsnum, "", (), intret(numcurslots()));

/// Returns how many variant slots are globally registered for this map/slotregistry.
int numcurvslots()
{
    return getcurslotreg()->vslots.length();
}

/// Checks whether a specific vslot is in the current maps slotregistry.
bool hasslot(int index)
{
    return getcurslotreg()->slots.inrange(index);
}

/// Checks whether a specific vslot is in the current maps slotregistry.
bool hasvslot(int index)
{
    return getcurslotreg()->vslots.inrange(index);
}

/// Get a reference to a specific slot AND load it if not specified otherwise.
/// If it fails its a reference to a dummyslot.
Slot &lookupslot(int index, bool load)
{
    vector<Slot *> &slots = getcurslotreg()->slots;
    Slot &s = slots.inrange(index) ? *slots[index] : (slots.inrange(DEFAULT_GEOM) ? *slots[DEFAULT_GEOM] : dummyslot);
    return s.loaded || !load ? s : s.load(true, false);
}

/// Get a reference to a specific vslot AND load it if not specified otherwise.
/// if it fails its a reference to a dummyvslot.
VSlot &lookupvslot(int index, bool load)
{
    vector<VSlot *> &vslots = getcurslotreg()->vslots;
    vector<Slot *> &slots = getcurslotreg()->slots;
    VSlot &s = vslots.inrange(index) && vslots[index]->slot ? *vslots[index] : 
                    (slots.inrange(DEFAULT_GEOM) && slots[DEFAULT_GEOM]->variants ? *slots[DEFAULT_GEOM]->variants : dummyvslot);
    if(load && !s.linked)
    {
        if(!s.slot->loaded) s.slot->load(true, false);
        linkvslotshader(s);
        s.linked = true;
    }
    return s;
}

/// Get a reference to a specific materialslot AND load it if not specified otherwise.
/// TODO NO DUMMY AVAILABLE!!
MSlot &lookupmaterialslot(int index, bool load)
{
    MSlot &s = getcurslotreg()->materialslots[index];
    if(load && !s.linked)
    {
        if(!s.loaded) s.load(true, true);
        linkvslotshader(s);
        s.linked = true;
    }
    return s;
}

// TODO:
// - make textures look into texturefolder by default [DONE]
// - cutextension, cutfolder, getextension [DONE]
// - revert make json chars always allocated [DONE]
// - rename json getchild .. to child getfloat.. to getchildfloat( [DONE]
// - refractor foralljson to have an independend variablename [DONE]
// - replace
// - loadalltextures
// - statistik erstellen -> sortieren
// - alle texturen -> map texturen -> map json
// - import command für "#arg1" :


// LATER:
//// GRASS
//JSON *grass = j->getchild("grass"); // seperate entry, not in sts
//if(grass && grass->valuestring)
//{
//    s.autograss = new string;
//    filesystem::getmedianame(s.autograss, MAXSTRLEN, grass->valuestring, DIR_TEXTURE, grass);
//    nformatstring(s.autograss, MAXSTRLEN, "<premul>%s", s.autograss); // prefix
//}
////
