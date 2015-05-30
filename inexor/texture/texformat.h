/// 

#ifndef _TEX_FORMAT_H
#define _TEX_FORMAT_H

//#ifdef WIN32
///// we define our own math constants (PI, ln(2)...)
//#define _USE_MATH_DEFINED
//#endif
//
//#include <SDL.h>
//#include <SDL_opengl.h>
#include "texture/texsettings.h"

extern GLenum texformat(int bpp);
extern bool alphaformat(GLenum format);
extern GLenum uncompressedformat(GLenum format);
extern GLenum compressedformat(GLenum format, int w, int h, int force = 0);
extern GLenum textarget(GLenum subtarget);
extern int formatsize(GLenum format);

#endif _TEX_FORMAT_H
