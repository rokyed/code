/// @file everything to save images of various formats.

#ifndef _TEX_SAVETEXTURE_H
#define _TEX_SAVETEXTURE_H

#include "inexor/engine/engine.h"
#include "inexor/texture/texture.h"

enum
{
    IMG_BMP = 0,
    IMG_TGA = 1,
    IMG_PNG = 2,
    NUMIMG
};

extern void saveimage(const char *filename, int format, ImageData &image, bool flip = false);
extern int guessimageformat(const char *filename, int format = IMG_BMP);

extern void savepng(const char *filename, ImageData &image, bool flip = false);
extern void savetga(const char *filename, ImageData &image, bool flip = false);

#endif // _TEX_SAVETEXTURE_H
