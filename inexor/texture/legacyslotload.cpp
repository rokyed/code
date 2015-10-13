/// @file Legacy texture slot loading.

#include "inexor/engine/engine.h"
#include "inexor/shared/filesystem.h"

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
    inexor::filesystem::getmedianame(st.name, MAXSTRLEN, name, DIR_TEXTURE);

    path(st.name);
    if(tnum == TEX_DIFFUSE)
    {
        setslotshader(s);
        VSlot &vs = matslot >= 0 ? lookupmaterialslot(matslot, false) : *emptyvslot(s);
        vs.reset();
        vs.rotation = clamp(*rot, 0, 5);
        vs.offset = ivec2(*xoffset, *yoffset).max(0);
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
    s.autograss = name[0] ? newstring(makerelpath(getcurexecdir(), name, NULL, "<premul>")) : NULL;
}
COMMAND(autograss, "s");

/// Set the texture scrolling of the specified Slot to the given amount of x and y.
void slotscroll(int slotid, float scrollS, float scrollT)
{
    if(slots.empty() || !slots.inrange(slotid)) return;
    slots[slotid]->setscroll(scrollS, scrollT);
}

void texscroll(float *scrollS, float *scrollT)
{
    if(slots.empty()) return;
    slotscroll(slots.last()->index, *scrollS, *scrollT);
}
COMMAND(texscroll, "ff");

/// Shift the texture by a given percentage to x or y for given Slot.
void slotoffset(int slotid, int xoffset, int yoffset)
{
    if(slots.empty() || !slots.inrange(slotid)) return;
    slots[slotid]->setoffset(xoffset, yoffset);
}

void texoffset_(int *xoffset, int *yoffset)
{
    if(slots.empty()) return;
    slotoffset(slots.last()->index, *xoffset, *yoffset);

}
COMMANDN(texoffset, texoffset_, "ii");

/// Rotate the given Slotid around, just 90degree possible atm.
/// @param rot param for the rotation between 0 and 3 (0 or 4 beeing standard)
void slotrotate(int slotid, int rot)
{
    if(slots.empty() || !slots.inrange(slotid)) return;
    slots[slotid]->setrotate(rot);
}

void texrotate_(int *rot)
{
    if(slots.empty()) return;
    slotrotate(slots.last()->index, *rot);
}
COMMANDN(texrotate, texrotate_, "i");

/// Scale the texture by the given amount for the given Slot, will be clamped to poweroftwo values.
void slotscale(int slotid, float scale)
{
    if(slots.empty() || !slots.inrange(slotid)) return;
    slots[slotid]->setscale(scale);
}

void texscale(float *scale)
{
    if(slots.empty()) return;
    slotscale(slots.last()->index, *scale);
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

/// Set the transparency of given slot to given amount.
void slotalpha(int slotid, float front, float back)
{
    if(slots.empty() || !slots.inrange(slotid)) return;
    slots[slotid]->setalpha(front, back);
}

void texalpha(float *front, float *back)
{
    if(slots.empty()) return;
    slotalpha(slots.last()->index, *front, *back);
}
COMMAND(texalpha, "ff");

/// Colorify the given slot with the given red green blue amount.
/// param r floatvalue between 0 and 1, giving the red amount.
void slotcolor(int slotid, float r, float g, float b)
{
    if(slots.empty() || !slots.inrange(slotid)) return;
    slots[slotid]->setcolor(r, g, b);
}

void texcolor(float *r, float *g, float *b)
{
    if(slots.empty()) return;
    slotcolor(slots.last()->index, *r, *g, *b);
}
COMMAND(texcolor, "fff");

// TODO: replace slotid with reference to slot
// TODO: new arrangement for  createvariant, maybe own function where necessary?
// TODO: colorscale globally or sth? at least done properly with shaders?
// TODO: nice way to merge some propagetevslot calls?
