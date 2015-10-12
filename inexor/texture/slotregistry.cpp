/// @file Slotsets are used to load and organize texture-slots chunk wise.
///

#include "inexor/shared/filesystem.h"
#include "inexor/texture/slotregistry.h"

namespace inexor {
namespace texture {

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
            Slot::Tex &st = s.sts.add();
            st.type = i;
            st.combined = -1;
            st.t = NULL;
            filesystem::getmedianame(st.name, name, DIR_TEXTURE, sub);
            path(st.name);
        }

        JSON *grass = j->getchild("grass"); // seperate entry, not in sts
        if(grass && grass->valuestring)
        {
            s.autograss = new string;
            filesystem::getmedianame(s.autograss, grass->valuestring, DIR_TEXTURE, grass);
            nformatstring(s.autograss, MAXSTRLEN, "<premul>%s", s.autograss); // prefix
        }

        return s.sts.length() != 0;
    }

    /// Add all size/rotation/offset/scroll modifiers.
    void addvslotparams(Slot &s, JSON *j)
    {
        JSON *scale = j->getchild("scale"), *rot = j->getchild("rotation"), *offset = j->getchild("offset"),
        *scroll = j->getchild("scroll"), *alpha = j->getchild("alpha"), *color = j->getchild("color");

        VSlot &vs = *emptyvslot(s);
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

    void slotregistry::load()
    {
        loopv(slots)
        {
            slots[i]->load(true, false);
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
        filesystem::getmedianame(fname, name, DIR_TEXTURE);
        JSON *j = loadjson(fname);
        if(!j) { conoutf("could not load %s slotset", name); return; }
        slotregistry *t = new slotregistry(j);

        delete j;

        if(load) t->load();
    }

    /// Scan Texturedir for slotsets and load those sets.
    void scantexturedir()
    {
        vector<char *> files;
        listfiles(texturedir, "json", files, true, false, true);
        conoutf("Loaded %d texture configuration files", files.length());

        if(!files.length()) return;
        slotregistry *t = new slotregistry();
        loopv(files) t->addslot(files[i]);

        t->load();
        // t->mount();
    }
    COMMAND(scantexturedir, "");

    /// Echo all texture slots loaded.
    void debugslots()
    {
        int numtexs = 0;
        loopv(slots)
        {
            loopvk(slots[i]->sts) conoutf("%d (%d): %s", i, k, slots[i]->sts[k].name);
            numtexs += slots[i]->sts.length();
        }
        conoutf("%d slots taken..", slots.length());
        conoutf("having %d textures", numtexs);
    }
    COMMAND(debugslots, "");

}     // namespace texture
}     // namespace inexor



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
