/// @file environment map loading routine.

#ifndef _TEX_CUBEMAP_H
#define _TEX_CUBEMAP_H

#include "engine.h"

struct cubemapside
{
    GLenum target;
    const char *name;
    bool flipx, flipy, swapxy;
};

extern cubemapside cubemapsides[6];

extern Texture *cubemapload(const char *name, bool mipit = true, bool msg = true, bool transient = false);
extern Texture *cubemaploadwildcard(Texture *t, const char *name, bool mipit, bool msg, bool transient = false);

extern void initenvmaps();
extern void genenvmaps();
extern void clearenvmaps();

extern ushort closestenvmap(const vec &o);
extern ushort closestenvmap(int orient, int x, int y, int z, int size);
extern GLuint lookupenvmap(ushort emid);
extern GLuint lookupenvmap(Slot &slot);

// rendergl.cpp:
extern void drawcubemap(int size, const vec &o, float yaw, float pitch, const cubemapside &side);

#endif // _TEX_CUBEMAP_H
