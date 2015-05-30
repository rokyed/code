/// @file Texture modifiers applyable on load.

#ifndef TEX_MODIFIERS_H
#define TEX_MODIFIERS_H

#include "engine.h"
#include "texture/macros.h"
#include "texture/texsettings.h"

extern void scaletexture(uchar *src, uint sw, uint sh, uint bpp, uint pitch, uchar *dst, uint dw, uint dh);
extern void resizetexture(int w, int h, bool mipmap, bool canreduce, GLenum target, int compress, int &tw, int &th);
extern void scaleimage(ImageData &s, int w, int h);

extern void texoffset(ImageData &s, int xoffset, int yoffset);
extern void texrotate(ImageData &s, int numrots, int type = TEX_DIFFUSE);
extern void texreorient(ImageData &s, bool flipx, bool flipy, bool swapxy, int type = TEX_DIFFUSE);
extern void texflip(ImageData &s);

extern void texmad(ImageData &s, const vec &mul, const vec &add);
extern void texcolorify(ImageData &s, const vec &color, vec weights);
extern void texcolormask(ImageData &s, const vec &color1, const vec &color2);
extern void texffmask(ImageData &s, float glowscale, float envscale);
extern void texdup(ImageData &s, int srcchan, int dstchan);
extern void texdecal(ImageData &s);
extern void texmix(ImageData &s, int c1, int c2, int c3, int c4);
extern void texgrey(ImageData &s);
extern void texpremul(ImageData &s);
extern void texagrad(ImageData &s, float x2, float y2, float x1, float y1);
extern void texnormal(ImageData &s, int emphasis);
extern void texblur(ImageData &s, int n, int r);

extern void forcergbimage(ImageData &s);

#endif //TEX_MODIFIERS_H