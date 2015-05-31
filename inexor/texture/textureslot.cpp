/// 


#include "engine.h"
#include "texture/texture.h"
#include "texture/macros.h"
#include "texture/texmodifiers.h"
#include "texture/cubemap.h"
#include "texture/textureslot.h"

// management of texture slots
// each texture slot can have multiple texture frames, of which currently only the first is used
// additional frames can be used for various shaders

vector<VSlot *> vslots;
vector<Slot *> slots;
MSlot materialslots[(MATF_VOLUME | MATF_INDEX) + 1];
Slot dummyslot;
VSlot dummyvslot(&dummyslot);

/// Resolves a missing part of the texturestack so following textures wont be effected ingame.
void rewireslots(int first, int num)
{
    // TODO

}

/// Resets all textures from the slots-stack.
/// @param first: the texturepos from whereon you want to reset
/// @param num: the number of slots you want to reset from thereon. All if 0
/// @example texturereset(0, 40); resets the first 40 textures
void texturereset(int first, int num)
{
    if(!(identflags&IDF_OVERRIDDEN) && !game::allowedittoggle()) return;
    resetslotshader();
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

    rewireslots(first, num);
}

ICOMMAND(texturereset, "ii", (int *first, int *last), texturereset(*first, *last));

void materialreset()
{
    if(!(identflags&IDF_OVERRIDDEN) && !game::allowedittoggle()) return;
    loopi((MATF_VOLUME | MATF_INDEX) + 1) materialslots[i].reset();
}

COMMAND(materialreset, "");

static int compactedvslots = 0, compactvslotsprogress = 0, clonedvslots = 0;
static bool markingvslots = false;

void clearslots()
{
    resetslotshader();
    slots.deletecontents();
    vslots.deletecontents();
    loopi((MATF_VOLUME | MATF_INDEX) + 1) materialslots[i].reset();
    clonedvslots = 0;
}

static void assignvslot(VSlot &vs);

static inline void assignvslotlayer(VSlot &vs)
{
    if(vs.layer && vslots.inrange(vs.layer))
    {
        VSlot &layer = *vslots[vs.layer];
        if(layer.index < 0) assignvslot(layer);
    }
}

static void assignvslot(VSlot &vs)
{
    vs.index = compactedvslots++;
    assignvslotlayer(vs);
}

void compactvslot(int &index)
{
    if(vslots.inrange(index))
    {
        VSlot &vs = *vslots[index];
        if(vs.index < 0) assignvslot(vs);
        if(!markingvslots) index = vs.index;
    }
}

void compactvslots(cube *c, int n)
{
    if((compactvslotsprogress++ & 0xFFF) == 0) renderprogress(min(float(compactvslotsprogress) / allocnodes, 1.0f), markingvslots ? "marking slots..." : "compacting slots...");
    loopi(n)
    {
        if(c[i].children) compactvslots(c[i].children);
        else loopj(6) if(vslots.inrange(c[i].texture[j]))
        {
            VSlot &vs = *vslots[c[i].texture[j]];
            if(vs.index < 0) assignvslot(vs);
            if(!markingvslots) c[i].texture[j] = vs.index;
        }
    }
}

int compactvslots()
{
    clonedvslots = 0;
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
    extern int nompedit;
    if(nompedit && multiplayer()) return;
    compactvslots();
    allchanged();
});

static Slot &loadslot(Slot &s, bool forceload);

static void clampvslotoffset(VSlot &dst, Slot *slot = NULL)
{
    if(!slot) slot = dst.slot;
    if(slot && slot->sts.inrange(0))
    {
        if(!slot->loaded) loadslot(*slot, false);
        int xs = slot->sts[0].t->xs, ys = slot->sts[0].t->ys;
        if((dst.rotation & 5) == 1) swap(xs, ys);
        dst.xoffset %= xs; if(dst.xoffset < 0) dst.xoffset += xs;
        dst.yoffset %= ys; if(dst.yoffset < 0) dst.yoffset += ys;
    }
    else
    {
        dst.xoffset = max(dst.xoffset, 0);
        dst.yoffset = max(dst.yoffset, 0);
    }
}

static void propagatevslot(VSlot &dst, const VSlot &src, int diff, bool edit = false)
{
    if(diff & (1 << VSLOT_SHPARAM)) loopv(src.params) dst.params.add(src.params[i]);
    if(diff & (1 << VSLOT_SCALE)) dst.scale = src.scale;
    if(diff & (1 << VSLOT_ROTATION))
    {
        dst.rotation = src.rotation;
        if(edit && (dst.xoffset || dst.yoffset)) clampvslotoffset(dst);
    }
    if(diff & (1 << VSLOT_OFFSET))
    {
        dst.xoffset = src.xoffset;
        dst.yoffset = src.yoffset;
        if(edit) clampvslotoffset(dst);
    }
    if(diff & (1 << VSLOT_SCROLL))
    {
        dst.scrollS = src.scrollS;
        dst.scrollT = src.scrollT;
    }
    if(diff & (1 << VSLOT_LAYER)) dst.layer = src.layer;
    if(diff & (1 << VSLOT_ALPHA))
    {
        dst.alphafront = src.alphafront;
        dst.alphaback = src.alphaback;
    }
    if(diff & (1 << VSLOT_COLOR)) dst.colorscale = src.colorscale;
}

/// Apply changes to all following neighbors of root.
/// Making it accordingly to roots vslot
/// @param changed includes info about what changed
void propagatevslot(VSlot *root, int changed)
{
    for(VSlot *vs = root->next; vs; vs = vs->next)
    {
        int diff = changed & ~vs->changed;
        if(diff) propagatevslot(*vs, *root, diff);
    }
}

static void mergevslot(VSlot &dst, const VSlot &src, int diff, Slot *slot = NULL)
{
    if(diff & (1 << VSLOT_SHPARAM)) loopv(src.params)
    {
        const ShaderParam &sp = src.params[i];
        loopvj(dst.params)
        {
            ShaderParam &dp = dst.params[j];
            if(sp.name == dp.name)
            {
                memcpy(dp.val, sp.val, sizeof(dp.val));
                goto nextparam;
            }
        }
        dst.params.add(sp);
    nextparam:;
    }
    if(diff & (1 << VSLOT_SCALE))
    {
        dst.scale = clamp(dst.scale*src.scale, 1 / 8.0f, 8.0f);
    }
    if(diff & (1 << VSLOT_ROTATION))
    {
        dst.rotation = clamp(dst.rotation + src.rotation, 0, 5);
        if(dst.xoffset || dst.yoffset) clampvslotoffset(dst, slot);
    }
    if(diff & (1 << VSLOT_OFFSET))
    {
        dst.xoffset += src.xoffset;
        dst.yoffset += src.yoffset;
        clampvslotoffset(dst, slot);
    }
    if(diff & (1 << VSLOT_SCROLL))
    {
        dst.scrollS += src.scrollS;
        dst.scrollT += src.scrollT;
    }
    if(diff & (1 << VSLOT_LAYER)) dst.layer = src.layer;
    if(diff & (1 << VSLOT_ALPHA))
    {
        dst.alphafront = src.alphafront;
        dst.alphaback = src.alphaback;
    }
    if(diff & (1 << VSLOT_COLOR)) dst.colorscale.mul(src.colorscale);
}

void mergevslot(VSlot &dst, const VSlot &src, const VSlot &delta)
{
    dst.changed = src.changed | delta.changed;
    propagatevslot(dst, src, (1 << VSLOT_NUM) - 1);
    mergevslot(dst, delta, delta.changed, src.slot);
}

static bool comparevslot(const VSlot &dst, const VSlot &src, int diff)
{
    if(diff & (1 << VSLOT_SHPARAM))
    {
        if(src.params.length() != dst.params.length()) return false;
        loopv(src.params)
        {
            const ShaderParam &sp = src.params[i], &dp = dst.params[i];
            if(sp.name != dp.name || memcmp(sp.val, dp.val, sizeof(sp.val))) return false;
        }
    }
    if(diff & (1 << VSLOT_SCALE) && dst.scale != src.scale) return false;
    if(diff & (1 << VSLOT_ROTATION) && dst.rotation != src.rotation) return false;
    if(diff & (1 << VSLOT_OFFSET) && (dst.xoffset != src.xoffset || dst.yoffset != src.yoffset)) return false;
    if(diff & (1 << VSLOT_SCROLL) && (dst.scrollS != src.scrollS || dst.scrollT != src.scrollT)) return false;
    if(diff & (1 << VSLOT_LAYER) && dst.layer != src.layer) return false;
    if(diff & (1 << VSLOT_ALPHA) && (dst.alphafront != src.alphafront || dst.alphaback != src.alphaback)) return false;
    if(diff & (1 << VSLOT_COLOR) && dst.colorscale != src.colorscale) return false;
    return true;
}

VSlot *findvslot(Slot &slot, const VSlot &src, const VSlot &delta)
{
    for(VSlot *dst = slot.variants; dst; dst = dst->next)
    {
        if((!dst->changed || dst->changed == (src.changed | delta.changed)) &&
            comparevslot(*dst, src, src.changed & ~delta.changed) &&
            comparevslot(*dst, delta, delta.changed))
            return dst;
    }
    return NULL;
}

static VSlot *clonevslot(const VSlot &src, const VSlot &delta)
{
    VSlot *dst = vslots.add(new VSlot(src.slot, vslots.length()));
    dst->changed = src.changed | delta.changed;
    propagatevslot(*dst, src, ((1 << VSLOT_NUM) - 1) & ~delta.changed);
    propagatevslot(*dst, delta, delta.changed, true);
    return dst;
}

VARP(autocompactvslots, 0, 256, 0x10000);

VSlot *editvslot(const VSlot &src, const VSlot &delta)
{
    VSlot *exists = findvslot(*src.slot, src, delta);
    if(exists) return exists;
    if(vslots.length() >= 0x10000)
    {
        compactvslots();
        allchanged();
        if(vslots.length() >= 0x10000) return NULL;
    }
    if(autocompactvslots && ++clonedvslots >= autocompactvslots)
    {
        compactvslots();
        allchanged();
    }
    return clonevslot(src, delta);
}

static void fixinsidefaces(cube *c, const ivec &o, int size, int tex)
{
    loopi(8)
    {
        ivec co(i, o.x, o.y, o.z, size);
        if(c[i].children) fixinsidefaces(c[i].children, co, size >> 1, tex);
        else loopj(6) if(!visibletris(c[i], j, co.x, co.y, co.z, size))
            c[i].texture[j] = tex;
    }
}

ICOMMAND(fixinsidefaces, "i", (int *tex),
{
    extern int nompedit;
    if(noedit(true) || (nompedit && multiplayer())) return;
    fixinsidefaces(worldroot, ivec(0, 0, 0), worldsize >> 1, *tex && vslots.inrange(*tex) ? *tex : DEFAULT_GEOM);
    allchanged();
});

static int findtextype(Slot &s, int type, int last = -1)
{
    for(int i = last + 1; i<s.sts.length(); i++) if((type&(1 << s.sts[i].type)) && s.sts[i].combined<0) return i;
    return -1;
}

static void addbump(ImageData &c, ImageData &n, bool envmap, bool specmap)
{
    if(n.bpp < 3) return;
    if(envmap && c.bpp <= 3 && !specmap)
    {
        writetex(n, if(dst[2] < 0xF8) goto noenvmap;);
    }
    if(envmap)
    {
        if(c.bpp <= 3)
        {
            readwritergbatex(c, n,
                int z = max(int(src[2]) * 2 - 255, 0);
            loopk(3) dst[k] = int(dst[k])*z / 255;
            dst[3] = z;
            );
        }
        else
        {
            readwritergbatex(c, n,
                int z = max(int(src[2]) * 2 - 255, 0);
            loopk(4) dst[k] = int(dst[k])*z / 255;
            );
        }
    }
    else
    {
    noenvmap:
        readwritergbtex(c, n,
            int z = max(int(src[2]) * 2 - 255, 0);
        loopk(3) dst[k] = int(dst[k])*z / 255;
        );
    }
}

static void addglow(ImageData &c, ImageData &g, const vec &glowcolor)
{
    if(g.bpp < 3)
    {
        readwritergbtex(c, g,
            loopk(3) dst[k] = clamp(int(dst[k]) + int(src[0] * glowcolor[k]), 0, 255);
        );
    }
    else
    {
        readwritergbtex(c, g,
            loopk(3) dst[k] = clamp(int(dst[k]) + int(src[k] * glowcolor[k]), 0, 255);
        );
    }
}

static void blenddecal(ImageData &c, ImageData &d)
{
    if(d.bpp < 4) return;
    readwritergbtex(c, d,
        uchar a = src[3];
    loopk(3) dst[k] = (int(src[k])*int(a) + int(dst[k])*int(255 - a)) / 255;
    );
}

static void mergespec(ImageData &c, ImageData &s, bool envmap = false)
{
    if(s.bpp < 3)
    {
        if(envmap)
        {
            readwritergbatex(c, s,
                dst[3] = int(dst[3])*int(src[0]) / 255;
            );
        }
        else
        {
            readwritergbatex(c, s,
                dst[3] = src[0];
            );
        }
    }
    else if(envmap)
    {
        readwritergbatex(c, s,
            dst[3] = int(dst[3])*(int(src[0]) + int(src[1]) + int(src[2])) / (3 * 255);
        );
    }
    else
    {
        readwritergbatex(c, s,
            dst[3] = (int(src[0]) + int(src[1]) + int(src[2])) / 3;
        );
    }
}

static void mergedepth(ImageData &c, ImageData &z)
{
    readwritergbatex(c, z,
        dst[3] = src[0];
    );
}

static void addname(vector<char> &key, Slot &slot, Slot::Tex &t, bool combined = false, const char *prefix = NULL)
{
    if(combined) key.add('&');
    if(prefix) { while(*prefix) key.add(*prefix++); }
    for(const char *s = path(t.name); *s; key.add(*s++));
}

static void texcombine(Slot &s, int index, Slot::Tex &t, bool forceload = false)
{
    if(renderpath == R_FIXEDFUNCTION && t.type != TEX_DIFFUSE && t.type != TEX_GLOW && !forceload) { t.t = notexture; return; }
    vector<char> key;
    addname(key, s, t);
    int texmask = 0;
    bool envmap = renderpath == R_FIXEDFUNCTION && s.shader->type&SHADER_ENVMAP && s.ffenv && hasCM && maxtmus >= 2;
    if(!forceload) switch(t.type)
    {
    case TEX_DIFFUSE:
        if(renderpath == R_FIXEDFUNCTION)
        {
            int mask = (1 << TEX_DECAL) | (1 << TEX_NORMAL);
            if(envmap) mask |= 1 << TEX_SPEC;
            for(int i = -1; (i = findtextype(s, mask, i)) >= 0;)
            {
                texmask |= 1 << s.sts[i].type;
                s.sts[i].combined = index;
                addname(key, s, s.sts[i], true, envmap && (s.sts[i].type == TEX_NORMAL || s.sts[i].type == TEX_SPEC) ? "<ffenv>" : NULL);
            }
            break;
        } // fall through to shader case

    case TEX_NORMAL:
    {
        if(renderpath == R_FIXEDFUNCTION) break;
        int i = findtextype(s, t.type == TEX_DIFFUSE ? (1 << TEX_SPEC) : (1 << TEX_DEPTH));
        if(i<0) break;
        texmask |= 1 << s.sts[i].type;
        s.sts[i].combined = index;
        addname(key, s, s.sts[i], true);
        break;
    }
    }
    key.add('\0');
    t.t = gettexture(key.getbuf()); //todo check if working
    if(t.t) return;
    int compress = 0;
    ImageData ts;
    if(!texturedata(ts, NULL, &t, true, &compress)) { t.t = notexture; return; }
    switch(t.type)
    {
    case TEX_DIFFUSE:
        if(renderpath == R_FIXEDFUNCTION)
        {
            if(!ts.compressed) loopv(s.sts)
            {
                Slot::Tex &b = s.sts[i];
                if(b.combined != index) continue;
                ImageData bs;
                if(!texturedata(bs, NULL, &b)) continue;
                if(bs.w != ts.w || bs.h != ts.h) scaleimage(bs, ts.w, ts.h);
                switch(b.type)
                {
                case TEX_DECAL: blenddecal(ts, bs); break;
                case TEX_NORMAL: addbump(ts, bs, envmap, (texmask&(1 << TEX_SPEC)) != 0); break;
                case TEX_SPEC: mergespec(ts, bs, envmap); break;
                }
            }
            break;
        } // fall through to shader case

    case TEX_NORMAL:
        if(!ts.compressed) loopv(s.sts)
        {
            Slot::Tex &a = s.sts[i];
            if(a.combined != index) continue;
            ImageData as;
            if(!texturedata(as, NULL, &a)) continue;
            //if(ts.bpp!=4) forcergbaimage(ts);
            if(as.w != ts.w || as.h != ts.h) scaleimage(as, ts.w, ts.h);
            switch(a.type)
            {
            case TEX_SPEC: mergespec(ts, as); break;
            case TEX_DEPTH: mergedepth(ts, as); break;
            }
            break; // only one combination
        }
        break;
    }
    t.t = newtexture(NULL, key.getbuf(), ts, 0, true, true, true, compress);
}

static Slot &loadslot(Slot &s, bool forceload)
{
    linkslotshader(s);
    loopv(s.sts)
    {
        Slot::Tex &t = s.sts[i];
        if(t.combined >= 0) continue;
        switch(t.type)
        {
        case TEX_ENVMAP:
            if(hasCM && (renderpath != R_FIXEDFUNCTION || (s.shader->type&SHADER_ENVMAP && s.ffenv && maxtmus >= 2) || forceload)) t.t = cubemapload(t.name);
            break;

        default:
            texcombine(s, i, t, forceload);
            break;
        }
    }
    s.loaded = true;
    return s;
}

MSlot &lookupmaterialslot(int index, bool load)
{
    MSlot &s = materialslots[index];
    if(load && !s.linked)
    {
        if(!s.loaded) loadslot(s, true);
        linkvslotshader(s);
        s.linked = true;
    }
    return s;
}

Slot &lookupslot(int index, bool load)
{
    Slot &s = slots.inrange(index) ? *slots[index] : (slots.inrange(DEFAULT_GEOM) ? *slots[DEFAULT_GEOM] : dummyslot);
    return s.loaded || !load ? s : loadslot(s, false);
}

VSlot &lookupvslot(int index, bool load)
{
    VSlot &s = vslots.inrange(index) && vslots[index]->slot ? *vslots[index] : (slots.inrange(DEFAULT_GEOM) && slots[DEFAULT_GEOM]->variants ? *slots[DEFAULT_GEOM]->variants : dummyvslot);
    if(load && !s.linked)
    {
        if(!s.slot->loaded) loadslot(*s.slot, false);
        linkvslotshader(s);
        s.linked = true;
    }
    return s;
}

void linkslotshaders()
{
    loopv(slots) if(slots[i]->loaded) linkslotshader(*slots[i]);
    loopv(vslots) if(vslots[i]->linked) linkvslotshader(*vslots[i]);
    loopi((MATF_VOLUME | MATF_INDEX) + 1) if(materialslots[i].loaded)
    {
        linkslotshader(materialslots[i]);
        linkvslotshader(materialslots[i]);
    }
}

Texture *loadthumbnail(Slot &slot)
{
    if(slot.thumbnail) return slot.thumbnail;
    if(!slot.variants)
    {
        slot.thumbnail = notexture;
        return slot.thumbnail;
    }
    VSlot &vslot = *slot.variants;
    linkslotshader(slot, false);
    linkvslotshader(vslot, false);
    vector<char> name;
    if(vslot.colorscale == vec(1, 1, 1)) addname(name, slot, slot.sts[0], false, "<thumbnail>");
    else
    {
        defformatstring(prefix)("<thumbnail:%.2f/%.2f/%.2f>", vslot.colorscale.x, vslot.colorscale.y, vslot.colorscale.z);
        addname(name, slot, slot.sts[0], false, prefix);
    }
    int glow = -1;
    if(slot.texmask&(1 << TEX_GLOW))
    {
        loopvj(slot.sts) if(slot.sts[j].type == TEX_GLOW) { glow = j; break; }
        if(glow >= 0)
        {
            defformatstring(prefix)("<glow:%.2f/%.2f/%.2f>", vslot.glowcolor.x, vslot.glowcolor.y, vslot.glowcolor.z);
            addname(name, slot, slot.sts[glow], true, prefix);
        }
    }
    VSlot *layer = vslot.layer ? &lookupvslot(vslot.layer, false) : NULL;
    if(layer)
    {
        if(layer->colorscale == vec(1, 1, 1)) addname(name, *layer->slot, layer->slot->sts[0], true, "<layer>");
        else
        {
            defformatstring(prefix)("<layer:%.2f/%.2f/%.2f>", vslot.colorscale.x, vslot.colorscale.y, vslot.colorscale.z);
            addname(name, *layer->slot, layer->slot->sts[0], true, prefix);
        }
    }
    name.add('\0');
    Texture *t = gettexture(name.getbuf());
    if(t) slot.thumbnail = t;
    else
    {
        ImageData s, g, l;
        texturedata(s, NULL, &slot.sts[0], false);
        if(glow >= 0) texturedata(g, NULL, &slot.sts[glow], false);
        if(layer) texturedata(l, NULL, &layer->slot->sts[0], false);
        if(!s.data) t = slot.thumbnail = notexture;
        else
        {
            if(vslot.colorscale != vec(1, 1, 1)) texmad(s, vslot.colorscale, vec(0, 0, 0));
            int xs = s.w, ys = s.h;
            if(s.w > 64 || s.h > 64) scaleimage(s, min(s.w, 64), min(s.h, 64));
            if(g.data)
            {
                if(g.w != s.w || g.h != s.h) scaleimage(g, s.w, s.h);
                addglow(s, g, vslot.glowcolor);
            }
            if(l.data)
            {
                if(layer->colorscale != vec(1, 1, 1)) texmad(l, layer->colorscale, vec(0, 0, 0));
                if(l.w != s.w / 2 || l.h != s.h / 2) scaleimage(l, s.w / 2, s.h / 2);
                forcergbimage(s);
                forcergbimage(l);
                uchar *dstrow = &s.data[s.pitch*l.h + s.bpp*l.w], *srcrow = l.data;
                loop(y, l.h)
                {
                    for(uchar *dst = dstrow, *src = srcrow, *end = &srcrow[l.w*l.bpp]; src < end; dst += s.bpp, src += l.bpp)
                        loopk(3) dst[k] = src[k];
                    dstrow += s.pitch;
                    srcrow += l.pitch;
                }
            }
            t = newtexture(NULL, name.getbuf(), s, 0, false, false, true);
            t->xs = xs;
            t->ys = ys;
            slot.thumbnail = t;
        }
    }
    return t;
}

void loadlayermasks()
{
    loopv(slots)
    {
        Slot &slot = *slots[i];
        if(slot.loaded && slot.layermaskname && !slot.layermask)
        {
            slot.layermask = new ImageData;
            texturedata(*slot.layermask, slot.layermaskname);
            if(!slot.layermask->data) DELETEP(slot.layermask);
        }
    }
}

void cleanupslots()
{
    loopv(slots) slots[i]->cleanup();
}

void cleanupvslots()
{
    loopv(vslots) vslots[i]->cleanup();
}

void cleanupmaterialslots()
{
    loopi((MATF_VOLUME | MATF_INDEX) + 1) materialslots[i].cleanup();
}
