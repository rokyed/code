/// @file management of texture slots as visible ingame.
/// each texture slot can have multiple texture frames, of which currently only the first is used
/// additional frames can be used for various shaders

#ifndef _TEX_SLOT_H
#define _TEX_SLOT_H

struct Slot;

enum
{
    VSLOT_SHPARAM = 0,
    VSLOT_SCALE,
    VSLOT_ROTATION,
    VSLOT_OFFSET,
    VSLOT_SCROLL,
    VSLOT_LAYER,
    VSLOT_ALPHA,
    VSLOT_COLOR,
    VSLOT_NUM
};

struct VSlot
{
    Slot *slot;
    VSlot *next;
    int index, changed;
    vector<ShaderParam> params;
    bool linked;
    float scale;
    int rotation, xoffset, yoffset;
    float scrollS, scrollT;
    int layer;
    float alphafront, alphaback;
    vec colorscale;
    vec glowcolor, pulseglowcolor;
    float pulseglowspeed;
    vec envscale;
    int skipped;

    VSlot(Slot *slot = NULL, int index = -1) : slot(slot), next(NULL), index(index), changed(0), skipped(0)
    {
        reset();
        if(slot) addvariant(slot);
    }

    void addvariant(Slot *slot);

    void reset()
    {
        params.shrink(0);
        linked = false;
        scale = 1;
        rotation = xoffset = yoffset = 0;
        scrollS = scrollT = 0;
        layer = 0;
        alphafront = 0.5f;
        alphaback = 0;
        colorscale = vec(1, 1, 1);
        glowcolor = vec(1, 1, 1);
        pulseglowcolor = vec(0, 0, 0);
        pulseglowspeed = 0;
        envscale = vec(0, 0, 0);
    }

    void cleanup()
    {
        linked = false;
    }
};

struct Slot
{
    struct Tex
    {
        int type;
        Texture *t;
        string name;
        int combined;
    };

    int index;
    vector<Tex> sts;
    Shader *shader;
    vector<ShaderParam> params;
    VSlot *variants;
    bool loaded;
    uint texmask;
    char *autograss;
    Texture *grasstex, *thumbnail;
    char *layermaskname;
    int layermaskmode;
    float layermaskscale;
    ImageData *layermask;
    bool ffenv;

    Slot(int index = -1) : index(index), variants(NULL), autograss(NULL), layermaskname(NULL), layermask(NULL) { reset(); }

    void reset()
    {
        sts.shrink(0);
        shader = NULL;
        params.shrink(0);
        loaded = false;
        texmask = 0;
        DELETEA(autograss);
        grasstex = NULL;
        thumbnail = NULL;
        DELETEA(layermaskname);
        layermaskmode = 0;
        layermaskscale = 1;
        if(layermask) DELETEP(layermask);
        ffenv = false;
    }

    void cleanup()
    {
        loaded = false;
        grasstex = NULL;
        thumbnail = NULL;
        loopv(sts)
        {
            Tex &t = sts[i];
            t.t = NULL;
            t.combined = -1;
        }
    }
};

inline void VSlot::addvariant(Slot *slot)
{
    if(!slot->variants) slot->variants = this;
    else
    {
        VSlot *prev = slot->variants;
        while(prev->next) prev = prev->next;
        prev->next = this;
    }
}

struct MSlot : Slot, VSlot
{
    MSlot() : VSlot(this) {}

    void reset()
    {
        Slot::reset();
        VSlot::reset();
    }

    void cleanup()
    {
        Slot::cleanup();
        VSlot::cleanup();
    }
};

Slot &loadslot(Slot &s, bool forceload, texsettings *tst = NULL);
extern void loadlayermasks();

extern void clearslots();
extern void cleanupslots();
extern void cleanupvslots();
extern void cleanupmaterialslots();

extern void propagatevslot(VSlot *root, int changed);
extern void texturereset(int first, int num = 0);

extern MSlot &lookupmaterialslot(int slot, bool load = true);
extern Slot &lookupslot(int slot, bool load = true);
extern VSlot &lookupvslot(int slot, bool load = true);
extern VSlot *emptyvslot(Slot &owner);

extern VSlot *findvslot(Slot &slot, const VSlot &src, const VSlot &delta);
extern VSlot *editvslot(const VSlot &src, const VSlot &delta);
extern void mergevslot(VSlot &dst, const VSlot &src, const VSlot &delta);


extern void compactvslots(cube *c, int n = 8);
extern void compactvslot(int &index);
extern int compactvslots();

extern vector<Slot *> slots;
extern vector<VSlot *> vslots;

#endif //_TEX_SLOT_H
