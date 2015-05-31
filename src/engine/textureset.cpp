///  Texturesets are used to load texture-stacks asynchronously
///

#include "textureset.h"

static VSlot *reassignvslot(Slot &owner, VSlot *vs);
static VSlot *emptyvslot(Slot &owner);

namespace inexor {
    namespace textureset {

        struct jsontextype {
            const char *name;
            int type;
        } jsontextypes[8] = {
            { "diffuse", TEX_DIFFUSE },
            { "other", TEX_UNKNOWN },
            { "decal", TEX_DECAL },
            { "normal", TEX_NORMAL },
            { "glow", TEX_GLOW },
            { "spec", TEX_SPEC },
            { "depth", TEX_DEPTH },
            { "envmap", TEX_ENVMAP }
        }; //todo: int gettype() function and const char *getjsontex to not iterate over TEX_NUM

        void textureset::addtexture(JSON *j)
        {
            if(!j || texs.length() >= 0x10000) return;

            Slot &s = *texs.add(new texentry(new Slot(texs.length())))->tex;
            s.loaded = false;
            loopi(TEX_NUM) //check for all 8 kind of textures
            {
                JSON *sub = j->getchild(jsontextypes[i].name);
                if(i == TEX_DIFFUSE && !sub) return; // no diffuse texture: other stuff wont work?
                else if(!sub) continue;
                char *name = sub->valuestring;
                if(!name) continue;
                s.texmask |= 1 << i;
                Slot::Tex &st = s.sts.add();
                st.type = i;
                st.combined = -1;
                st.t = NULL;

                filesystem::getmedianame(st.name, name, DIR_TEXTURE, sub);
                conoutf("st.name %s %s %s", st.name, name, texturedir);

                path(st.name);
            }
            if(!s.sts.length()) return; // no textures found

            setslotshader(s, j->getchild("shader")); // TODO: multithread

            //Other Parameters:
            JSON *scale = j->getchild("scale"), *rot = j->getchild("rotation"),
                *xoff = j->getchild("xoffset"), *yoff = j->getchild("yoffset");

            VSlot &vs = *emptyvslot(s);
            vs.reset();
            vs.rotation = rot ? clamp(rot->valueint, 0, 5) : 0;
            vs.xoffset = xoff ? max(xoff->valueint, 0) : 0;
            vs.yoffset = yoff ? max(yoff->valueint, 0) : 0;
            vs.scale = scale ? scale->valuefloat : 1;
            propagatevslot(&vs, (1 << VSLOT_NUM) - 1);
        }

        void textureset::addtexture(const char *filename)
        {
            if (!filename || !*filename) return;
            JSON *j = loadjson(filename);
            if (!j) {
                conoutf("could not load texture definition %s", filename); return;
            }

            addtexture(j);
            delete j;
        }

        void textureset::checkload()
        {
            loopv(texs)
            {
                texentry *t = texs[i];
                int diff = t->tex->texmask & ~t->loadmask; // All textures which havent been loaded yet
                if(!diff) continue;
                loopk(TEX_NUM)
                {
                    if(k >= t->tex->sts.length()) break; // out of range
                    if(!(diff & (1 << k))) continue; // not in diff
                    Slot::Tex &curimg = t->tex->sts[k];
                    curimg.t = gettexture(curimg.name);
                    if(curimg.t) t->loadmask |= 1 << k; //save to loadmask on success
                }
            }
        }

        void textureset::load()
        {
            loopv(texs)
            {
                texentry *t = texs[i];
                int needload = t->tex->texmask & ~t->loadmask;
                if(!needload) continue;
                loopk(TEX_NUM)
                {
                    if(k >= t->tex->sts.length()) break; // out of range
                    if(!(needload & (1 << k))) continue; // not in diff
                    Slot::Tex &st = t->tex->sts[k];
                    st.t = textureload(st.name, 0, true, false, true);
                    if(st.t != notexture) t->needregister |= 1 << k; // remember to register
                }
            }
        }

        void textureset::registerload()
        {
            loopv(texs)
            {
                texentry *t = texs[i];
                if(!t->needregister) continue;
                loopk(TEX_NUM)
                {
                    if(k >= t->tex->sts.length()) break; // out of range
                    if(t->needregister & (1 << k)) registertexture(t->tex->sts[k].name);
                }
            }
        }

        void textureset::mount(bool initial = false)
        {
            if(initial) texturereset(0);
            loopv(texs)
            {
                slots.add(texs[i]->tex);
                texs[i]->mounted = true;
            }
        }

        void textureset::unmount()
        {
            if(!texs[0]) return;
            int start = 0;
            loopv(slots)
            {
                if(slots[i] == texs[0]->tex) start = i;
            }

            texturereset(start, texs.length());

            loopv(texs) texs[i]->mounted = false;
        }

        /// Creates a textureset with all textures from a "textures" child of given JSON structure.
        /// @sideeffects allocates memory for a new textureset
        textureset *newtextureset(JSON *parent)
        {
            if (!parent) return NULL;
            JSON *j = parent->getchild("textures");
            if(!j) return NULL;
            textureset *t = new textureset();

            loopi(j->numchilds())
            {
                const char *name = j->getchildstring(i);
                defformatstring(fn) ("%s", name);
                if(name[0]!='/') formatstring(fn)("%s", makerelpath(parentdir(j->currentfile), name)); //relative path to current folder
                t->addtexture(fn);
            }
            return t;
        }

        bool loadset(const char *name)
        {
            string fname;
            filesystem::getmedianame(fname, name, DIR_TEXTURE);
            JSON *j = loadjson(fname);
            if(!j) { conoutf("could not load %s textureset", name); return false; }
            textureset *t = newtextureset(j);

            delete j;
            t->echoall();
            t->checkload();
            t->load();
            t->registerload();
            t->mount();
            //delete t;
            return true;
        }
        COMMAND(loadset, "s");

        /// Scan Texturedir for texturesets and load those sets.
        void scantexturedir()
        {
            vector<char *> files;
            listfiles(texturedir, "json", files);

            if(!files.length()) return;
            textureset *t = new textureset();
            loopv(files) t->addtexture(files[i]);

            t->checkload();
            t->load();
            t->registerload();
            t->mount();
        }
        COMMAND(scantexturedir, "");

        /// Guess a shader according to the used textures, allocates string.
        /// @param texmask a bitmaks containing the loaded textures
        const char *guessshader(int texmask)
        {
            // "bumpenvspecmapparallaxglowworld" with all textures

            if(texmask == (1 << TEX_DIFFUSE)) return newstring("stdworld");

            string shader;
            shader[0] = '\0';
            if(texmask&(1 << TEX_NORMAL)) strcat(shader, "bump");
            if(texmask&(1 << TEX_ENVMAP)) strcat(shader, "env");
            if(texmask&(1 << TEX_SPEC))   strcat(shader, "specmap");
            if(texmask&(1 << TEX_DEPTH))  strcat(shader, "parallax");
            if(texmask&(1 << TEX_NORMAL)) strcat(shader, "glow");

            strcat(shader, "world");

            return newstring(shader);
        }

        // Add VSlot depending entries to root.
        void createvslotentries(JSON *root, VSlot *vs)
        {
            if(vs->scale != 1.0f)
            {
                JSON *scale = JSON_CreateFloat(vs->scale);
                root->addchild("scale", scale);
            }
            if(vs->rotation)
            {
                JSON *rot = JSON_CreateInt(vs->rotation);
                root->addchild("rotation", rot);
            }
            if(vs->xoffset)
            {
                JSON *xoff = JSON_CreateInt(vs->xoffset);
                root->addchild("xoffset", xoff);
            }

            if(vs->yoffset)
            {
                JSON *yoff = JSON_CreateInt(vs->yoffset);
                root->addchild("yoffset", yoff);
            }
        }

        /// Exporter/Create texture jsons for already loaded slots.
        /// Loaded probably through the legacy path.
        void gentexjsons()
        {
            loopvk(vslots)
            {
                VSlot *vs = vslots[k];
                Slot *s = vs->slot;
                if(!s) continue;

                JSON *root = JSON_CreateObject();

                string diffusefile; //name the json accordingly to the diffuse file

                JSON *shader; //add an "shader" entry
                const char *shaderguess = guessshader(s->texmask);
                if(strcmp(shaderguess, s->shader->name) && !strcmp(s->shader->name, "stdworld"))
                { // optimize wrong shader setup (e.g. using not as many info-textures as possible )
                    shader = JSON_CreateString(shaderguess);
                }
                else shader = JSON_CreateString(s->shader->name);
                root->addchild("shader", shader);

                loopv(s->sts) // add all textures
                {
                    Slot::Tex *st = &s->sts[i];
                    defformatstring(name)("%s", st->name);
                    cutdir(name);
                    JSON *tex = JSON_CreateString(name);
                    root->addchild(jsontextypes[st->type].name, tex);

                    if(st->type == TEX_DIFFUSE) copystring(diffusefile, st->name);
                }

                createvslotentries(root, vs);

                cutextension(diffusefile);
                defformatstring(fn)("%s.json", diffusefile);

                const char *found = findfile(fn, "w"); // do not overwrite stuff

                if(root->save(fn))  conoutf("generated %s", fn);

                delete[] shaderguess;
                delete root;
            }
        }
        COMMAND(gentexjsons, "");

    } // namespace textureset
}     // namespace inexor

////// Original Loading /////
static VSlot *reassignvslot(Slot &owner, VSlot *vs)
{
    owner.variants = vs;
    while(vs)
    {
        vs->slot = &owner;
        vs->linked = false;
        vs = vs->next;
    }
    return owner.variants;
}

static VSlot *emptyvslot(Slot &owner)
{
    int offset = 0;
    loopvrev(slots) if(slots[i]->variants) { offset = slots[i]->variants->index + 1; break; }
    for(int i = offset; i < vslots.length(); i++) if(!vslots[i]->changed) return reassignvslot(owner, vslots[i]);
    return vslots.add(new VSlot(&owner, vslots.length()));
}

const struct slottex
{
    const char *name;
    int id;
} slottexs[] =
{
    { "c", TEX_DIFFUSE },
    { "u", TEX_UNKNOWN },
    { "d", TEX_DECAL },
    { "n", TEX_NORMAL },
    { "g", TEX_GLOW },
    { "s", TEX_SPEC },
    { "z", TEX_DEPTH },
    { "e", TEX_ENVMAP }
};

int findslottex(const char *name)
{
    loopi(sizeof(slottexs) / sizeof(slottex))
    {
        if(!strcmp(slottexs[i].name, name)) return slottexs[i].id;
    }
    return -1;
}

void texture(char *type, char *name, int *rot, int *xoffset, int *yoffset, float *scale)
{
    if(slots.length() >= 0x10000) return;
    if(!type || !name) return;

    static int lastmatslot = -1;
    int tnum = findslottex(type), matslot = findmaterial(type);
    if(tnum < 0) tnum = atoi(type);
    if(tnum == TEX_DIFFUSE) lastmatslot = matslot;
    else if(lastmatslot >= 0) matslot = lastmatslot;
    else if(slots.empty()) return;
    Slot &s = matslot >= 0 ? lookupmaterialslot(matslot, false) : *(tnum != TEX_DIFFUSE ? slots.last() : slots.add(new Slot(slots.length())));
    s.loaded = false;
    s.texmask |= 1 << tnum;
    if(s.sts.length() >= 8) conoutf(CON_WARN, "warning: too many textures in slot %d", slots.length() - 1);
    Slot::Tex &st = s.sts.add();
    st.type = tnum;
    st.combined = -1;
    st.t = NULL;
    inexor::filesystem::getmedianame(st.name, name, DIR_TEXTURE);

    path(st.name);
    if(tnum == TEX_DIFFUSE)
    {
        setslotshader(s);
        VSlot &vs = matslot >= 0 ? lookupmaterialslot(matslot, false) : *emptyvslot(s);
        vs.reset();
        vs.rotation = clamp(*rot, 0, 5);
        vs.xoffset = max(*xoffset, 0);
        vs.yoffset = max(*yoffset, 0);
        vs.scale = *scale <= 0 ? 1 : *scale;
        propagatevslot(&vs, (1 << VSLOT_NUM) - 1);
    }
    //conoutf(CON_WARN, "old texture loaded, should it be converted?")
}
COMMAND(texture, "ssiiif");

///// LEGACY TEX MODIFIERS ////

void autograss(char *name)
{
    if(slots.empty()) return;
    Slot &s = *slots.last();
    DELETEA(s.autograss);
    s.autograss = name[0] ? newstring(makerelpath(getcurexecdir(), name, NULL, "<ffskip><premul>")) : NULL;
}
COMMAND(autograss, "s");

void texscroll(float *scrollS, float *scrollT)
{
    if(slots.empty()) return;
    Slot &s = *slots.last();
    s.variants->scrollS = *scrollS / 1000.0f;
    s.variants->scrollT = *scrollT / 1000.0f;
    propagatevslot(s.variants, 1 << VSLOT_SCROLL);
}
COMMAND(texscroll, "ff");

void texoffset_(int *xoffset, int *yoffset)
{
    if(slots.empty()) return;
    Slot &s = *slots.last();
    s.variants->xoffset = max(*xoffset, 0);
    s.variants->yoffset = max(*yoffset, 0);
    propagatevslot(s.variants, 1 << VSLOT_OFFSET);
}
COMMANDN(texoffset, texoffset_, "ii");

void texrotate_(int *rot)
{
    if(slots.empty()) return;
    Slot &s = *slots.last();
    s.variants->rotation = clamp(*rot, 0, 5);
    propagatevslot(s.variants, 1 << VSLOT_ROTATION);
}
COMMANDN(texrotate, texrotate_, "i");

void texscale(float *scale)
{
    if(slots.empty()) return;
    Slot &s = *slots.last();
    s.variants->scale = *scale <= 0 ? 1 : *scale;
    propagatevslot(s.variants, 1 << VSLOT_SCALE);
}
COMMAND(texscale, "f");

void texlayer(int *layer, char *name, int *mode, float *scale)
{
    if(slots.empty()) return;
    Slot &s = *slots.last();
    s.variants->layer = *layer < 0 ? max(slots.length() - 1 + *layer, 0) : *layer;
    s.layermaskname = name[0] ? newstring(path(makerelpath(getcurexecdir(), name))) : NULL;
    s.layermaskmode = *mode;
    s.layermaskscale = *scale <= 0 ? 1 : *scale;
    propagatevslot(s.variants, 1 << VSLOT_LAYER);
}
COMMAND(texlayer, "isif");

void texalpha(float *front, float *back)
{
    if(slots.empty()) return;
    Slot &s = *slots.last();
    s.variants->alphafront = clamp(*front, 0.0f, 1.0f);
    s.variants->alphaback = clamp(*back, 0.0f, 1.0f);
    propagatevslot(s.variants, 1 << VSLOT_ALPHA);
}
COMMAND(texalpha, "ff");

void texcolor(float *r, float *g, float *b)
{
    if(slots.empty()) return;
    Slot &s = *slots.last();
    s.variants->colorscale = vec(clamp(*r, 0.0f, 1.0f), clamp(*g, 0.0f, 1.0f), clamp(*b, 0.0f, 1.0f));
    propagatevslot(s.variants, 1 << VSLOT_COLOR);
}
COMMAND(texcolor, "fff");

void texffenv(int *ffenv)
{
    if(slots.empty()) return;
    Slot &s = *slots.last();
    s.ffenv = *ffenv>0;
}
COMMAND(texffenv, "i");

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

// TODO:
// - make textures look into texturefolder by default
// - cutextension, cutfolder, getextension, replace
// - loadalltextures
// - statistik erstellen -> sortieren
// - alle texturen -> map texturen -> map json
// - import command für "#arg1" :
// - revert make json chars always allocated [DONE]
// - rename json getchild .. to child getfloat.. to getchildfloat( [DONE]
// - refractor foralljson to have an independend variablename [DONE]
