/// @file management of texture slots as visible ingame.
/// each texture slot can have multiple textures.
/// additional textures can be used for various shaders.
/// It is organized in two structures: virtual Slots and normal Slots.
/// Each Slot can have a node-chain of numerous virtual Slots which contain differing shader stuff,
/// like scale, color, rotation.. So a bunch of textures (a Slot) can easily be varying ingame.

#ifndef INEXOR_TEX_SLOT_H
#define INEXOR_TEX_SLOT_H

class Slot;

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

/// A virtual Slot (the ones you see in the texture browser)
/// @see slot.h file description for more info
class VSlot
{
  public:
    /// The Slot this VSlot derived from.
    Slot *slot;

    /// The next VSlot in the variant chain of the Slot.
    VSlot *next;

    /// Id of this slot in the current slotregistry.
    int index;

    /// A bitmask containing which values differ from the default ones.
    int changed;

    vector<SlotShaderParam> params;
    bool linked;

    // The actual params this VSlot provides:
    float scale;
    int rotation;
    ivec2 offset;
    vec2 scroll;
    int layer;
    float alphafront, alphaback;
    vec colorscale;
    vec glowcolor;

    VSlot(Slot *slot = NULL, int index = -1);

    void reset()
    {
        params.shrink(0);
        linked = false;
        scale = 1;
        rotation = 0;
        offset = ivec2(0, 0);
        scroll = vec2(0, 0);
        layer = 0;
        alphafront = 0.5f;
        alphaback = 0;
        colorscale = vec(1, 1, 1);
        glowcolor = vec(1, 1, 1);
    }

    void cleanup()
    {
        linked = false;
    }

    ///Pack a virtual Slot (e.g. after it has been modified) for broadcasting it to the other clients.
    /// @param buf the output buffer containing the network message like vslot info.
    void serialize(vector<uchar> &buf) const;

    /// Unpack a virtual Slot modified by another client.
    /// @param buf the buffer from the network packet containing the vslot info.
    /// @param delta
    bool unserialize(ucharbuf &buf, bool delta);

    /// Add all size/rotation/offset/scroll modifiers from a JSON file.
    void parsejson(JSON *j);

    /// Old Cube2 mapformat (ogz) method to load the vslot.
    /// @param f (file) stream.
    /// @param changed a bitmask containing the actual changed values, so new defaults will be preserved.
    void parsefromogz(stream *f, int changed);

    /// Save a VSlot to the Cube2 ogz file.
    void savetoogz(stream *f, int prev) const;

    /// Render a miniature preview image of this slot to the UI.
    /// @param x horizontal position on the screen (together with y for the vertical).
    /// @param w weight of the image (together with h beeing the height).
    /// @param color a base color to easily display that it's selected.
    bool renderthumbnail(int x, int y, int w, int h, const vec &color) const;
};

class Slot
{
public:
    /// bitmask containing which textures are already loaded.
    int loaded = 0;

    struct Tex
    {
        int type;
        Texture *t = NULL;
        string name;
        int combined = -1;
    };
    int index;
    vector<Tex> sts;
    Shader *shader;
    vector<SlotShaderParam> params;

    // All virtual Slots deriving from this slot in a node chain.
    VSlot *variants;
    uint texmask;
    char *autograss;
    Texture *grasstex, *thumbnail;
    char *layermaskname;
    int layermaskmode;
    float layermaskscale;
    ImageData *layermask;

    Slot(int index = -1) : index(index), variants(NULL), autograss(NULL), layermaskname(NULL), layermask(NULL) { reset(); }

    /// Constructor which adds all texture entries to the slottexture, taken from the json-file given.
    Slot(int index, JSON *j);

    void reset()
    {
        sts.shrink(0);
        shader = NULL;
        params.shrink(0);
        loaded = 0;
        texmask = 0;
        DELETEA(autograss);
        grasstex = NULL;
        thumbnail = NULL;
        DELETEA(layermaskname);
        layermaskmode = 0;
        layermaskscale = 1;
        if(layermask) DELETEP(layermask);
    }

    void cleanup()
    {
        loaded = 0;
        grasstex = NULL;
        thumbnail = NULL;
        loopv(sts)
        {
            Tex &t = sts[i];
            t.t = NULL;
            t.combined = -1;
        }
    }

    /// Find a texture in the sts array, depending on type (beeing one of TEX_DIFFUSE to TEX_NUM).
    Tex *findtexture(int type)
    {
        loopv(sts) if((1 << sts[i].type)&(1 << type)) return &sts[i];
        return NULL;
    }

    void addtexture(int type, const char *filename, const char *configdir);

    void addvariant(VSlot *vs);
    VSlot *setvariantchain(VSlot *vs);

    VSlot *findvariant(const VSlot &src, const VSlot &delta) const;

    void combinetextures(int index, Slot::Tex &t, bool msg = true, bool forceload = false);

    Slot &load(bool msg, bool forceload);
    Texture *loadthumbnail();
    void loadlayermask();

    /// Force values for all variant vslots:
    void setscroll(float scrollS, float scrollT);
    void setoffset(int xoffset, int yoffset);
    void setrotate(int rot);
    void setscale(float scale);
    void setalpha(float front, float back);
    void setcolor(float r, float g, float b);
    void setlayer(int *layer, char *name, int *mode, float *scale); // TODO, Layer uses vslots instead of references..
};

/// Material Slot, actually just a merge of Slot and VSlot
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

extern void propagatevslot(VSlot *root, int changed);
extern void propagatevslot(VSlot &dst, const VSlot &src, int diff, bool edit = false);
extern void mergevslot(VSlot &dst, const VSlot &src, const VSlot &delta);

#endif //INEXOR_TEX_SLOT_H

/// TODO make loaded correctly isloaded()
/// make emptyvslot obsolete by providing a better cleaning algorithm
