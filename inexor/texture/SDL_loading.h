/// @file SDL loading routine used to load into SDL Surfaces.

#ifndef _TEX_SDL_LOADING_H
#define _TEX_SDL_LOADING_H

#include "engine.h"
#include "SDL_image.h"

extern SDL_Surface *wrapsurface(void *data, int width, int height, int bpp);

extern bool canloadsurface(const char *name);
extern SDL_Surface *loadsurface(const char *name);

#endif //_TEX_SDL_LOADING_H