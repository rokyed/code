/// @file Slotsets are used to load and organize texture-slots chunk wise.
///

#include "inexor/filesystem/mediadirs.h"
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

    void slotregistry::addslot(JSON *j)
    {
        if(!j || slotlimitreached()) return;

        Slot *s = new Slot(slots.length(), j);

        if(s->sts.empty()) return; // no textures found

        JSON *shad = j->getchild("shader");
        setslotshader(*s, shad); // TODO: multithread

        addvslot(*s)->parsejson(j); // other vslot parameters
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

    #define MAXSLOTAMOUNT 0x10000
    #define MAXVSLOTAMOUNT 0x10000

    inline bool slotregistry::slotlimitreached() const
    {
        return slots.length() >= MAXSLOTAMOUNT;
    }

    // helper for addvslot.
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
        VSlot *ret = NULL;
        loopvrev(slots) if(slots[i]->variants) { offset = slots[i]->variants->index + 1; break; }
        for(int i = offset; i < vslots.length(); i++) if(!vslots[i]->changed) {
            owner.setvariantchain(vslots[i]); 
            ret = vslots[i];
            break;
        }
        if(!ret) ret = vslots.add(new VSlot(&owner, vslots.length()));
        ret->reset();
        return ret;
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

    void slotregistry::serializevslot(vector<uchar> &buf, int index) const
    {
        if(vslots.inrange(index)) vslots[index]->serialize(buf);
        else buf.put(0xFF);
    }

    void slotregistry::savetoogz(stream *f, int numvslots) const
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

// Legacy bridge:

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

// LEGACY "compacting" algorithm for the vslots (basicly to remove clutter, but probably can be written simpler i guess..)
// (formerly acting on globals and now simply using the current slotregistry)
// do not really fit the (new clean) class interface though (in its current form)

static int compactedvslots = 0, compactvslotsprogress = 0;
static bool markingvslots = false;

static void assignvslot(VSlot &vs);

static inline void assignvslotlayer(VSlot &vs)
{
    if(vs.layer && hasvslot(vs.layer))
    {
        VSlot &layer = lookupvslot(vs.layer, false);
        if(layer.index < 0) assignvslot(layer);
    }
}

/// Set the vs.index according to compactvslots global counter
static void assignvslot(VSlot &vs)
{
    vs.index = compactedvslots++;
    assignvslotlayer(vs);
}

///compacting mode: set index to compactvslots++ = vs.index, marking mode, just set vs.index
void compactvslot(int &index)
{
    if(hasvslot(index))
    {
        VSlot &vs = lookupvslot(index, false);
        if(vs.index < 0) assignvslot(vs);
        if(!markingvslots) index = vs.index;
    }
}

void compactvslot(VSlot &vs)
{
    if(vs.index < 0) assignvslot(vs);
}

/// Loops through all n subcubes of c, (reassigning vs.index to compactvslots++ in markmode and otherwise sets cubetexture to the new vslot) when texture was used
void compactvslots(cube *c, int n)
{
    if((compactvslotsprogress++ & 0xFFF) == 0) renderprogress(min(float(compactvslotsprogress) / allocnodes, 1.0f), markingvslots ? "marking slots..." : "compacting slots...");
    loopi(n)
    {
        if(c[i].children) compactvslots(c[i].children);
        else loopj(6) if(hasvslot(c[i].texture[j]))
        {
            VSlot &vs = lookupvslot(c[i].texture[j], false);
            if(vs.index < 0) assignvslot(vs);
            if(!markingvslots) c[i].texture[j] = vs.index;
        }
    }
}

// reset all indicies of the vslots
// the first indicies go to the first variants of all slots, then to all first variants layers
int compactvslots()
{
    static vector<Slot *> &slots = getcurslotreg()->slots;
    static vector<VSlot *> &vslots = getcurslotreg()->vslots;

    markingvslots = false;
    compactedvslots = 0;
    compactvslotsprogress = 0;
    loopv(vslots) vslots[i]->index = -1;
    loopv(slots) slots[i]->variants->index = compactedvslots++;
    loopv(slots) assignvslotlayer(*slots[i]->variants);
    loopv(vslots)
    {
        VSlot &vs = *vslots[i];
        if(!vs.changed && vs.index < 0) { markingvslots = true; break; }
    }
    compactvslots(worldroot);
    int total = compactedvslots;
    compacteditvslots();
    loopv(vslots)
    {
        VSlot *vs = vslots[i];
        if(vs->changed) continue;
        while(vs->next)
        {
            if(vs->next->index < 0) vs->next = vs->next->next;
            else vs = vs->next;
        }
    }
    if(markingvslots)
    {
        markingvslots = false;
        compactedvslots = 0;
        compactvslotsprogress = 0;
        int lastdiscard = 0;
        loopv(vslots)
        {
            VSlot &vs = *vslots[i];
            if(vs.changed || (vs.index < 0 && !vs.next)) vs.index = -1;
            else
            {
                while(lastdiscard < i)
                {
                    VSlot &ds = *vslots[lastdiscard++];
                    if(!ds.changed && ds.index < 0) ds.index = compactedvslots++;
                }
                vs.index = compactedvslots++;
            }
        }
        compactvslots(worldroot);
        total = compactedvslots;
        compacteditvslots();
    }
    compactmruvslots();
    loopv(vslots)
    {
        VSlot &vs = *vslots[i];
        if(vs.index >= 0 && vs.layer && vslots.inrange(vs.layer)) vs.layer = vslots[vs.layer]->index;
    }
    loopv(vslots)
    {
        while(vslots[i]->index >= 0 && vslots[i]->index != i)
            swap(vslots[i], vslots[vslots[i]->index]);
    }
    for(int i = compactedvslots; i < vslots.length(); i++) delete vslots[i];
    vslots.setsize(compactedvslots);
    return total;
}

ICOMMAND(compactvslots, "", (),
{
    extern SharedVar<int> nompedit;
    if(nompedit && multiplayer()) return;
    int oldamount = numcurvslots();
    compactvslots();
    conoutf("compacted virtual Slots (before: %d, now: %d)", oldamount, numcurvslots());
    allchanged();
});

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
