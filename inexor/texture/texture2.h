/// @file

#ifndef _TEX_TEXTURE_H
#define _TEX_TEXTURE_H

extern bool texturedata(ImageData &d, const char *tname, Slot::Tex *tex = NULL, bool msg = true, int *compress = NULL);
extern Texture *newtexture(Texture *t, const char *rname, ImageData &s, int clamp = 0, bool mipit = true, bool canreduce = false, bool transient = false, int compress = 0);

#endif // _TEX_TEXTURE_H
