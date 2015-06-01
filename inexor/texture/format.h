/// @file Small helper functions to organize which OpenGL formats to use.

#ifndef _TEX_FORMAT_H
#define _TEX_FORMAT_H

#include "inexor/shared/cube.h"
#include "inexor/texture/texsettings.h"


extern GLenum texformat(int bpp);
extern bool alphaformat(GLenum format);
extern GLenum uncompressedformat(GLenum format);
extern GLenum compressedformat(GLenum format, texsettings &tst, int w, int h, int force = 0);
extern GLenum textarget(GLenum subtarget);
extern int formatsize(GLenum format);

#endif //_TEX_FORMAT_H
