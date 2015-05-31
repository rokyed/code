/// @file Small helper functions to organize which OpenGL formats to use.

#include "texture/texformat.h"
#include "texture/texsettings.h"

GLenum texformat(int bpp)
{
    switch(bpp)
    {
    case 1: return GL_LUMINANCE;
    case 2: return GL_LUMINANCE_ALPHA;
    case 3: return GL_RGB;
    case 4: return GL_RGBA;
    default: return 0;
    }
}

bool alphaformat(GLenum format)
{
    switch(format)
    {
    case GL_ALPHA:
    case GL_LUMINANCE_ALPHA:
    case GL_RGBA:
        return true;
    default:
        return false;
    }
}

GLenum uncompressedformat(GLenum format)
{
    switch(format)
    {
    case GL_COMPRESSED_RGB_ARB:
    case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
        return GL_RGB;
    case GL_COMPRESSED_RGBA_ARB:
    case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
    case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
    case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
        return GL_RGBA;
    }
    return GL_FALSE;
}

GLenum compressedformat(GLenum format, int w, int h, int force)
{
    if(hasTC && usetexcompress && texcompress && force >= 0 && (force || w >= texcompress || h >= texcompress)) switch(format)
    {
    case GL_RGB5:
    case GL_RGB8:
    case GL_LUMINANCE:
    case GL_RGB: return usetexcompress > 1 ? GL_COMPRESSED_RGB_S3TC_DXT1_EXT : GL_COMPRESSED_RGB_ARB;
    case GL_LUMINANCE_ALPHA:
    case GL_RGBA: return usetexcompress > 1 ? GL_COMPRESSED_RGBA_S3TC_DXT5_EXT : GL_COMPRESSED_RGBA_ARB;
    }
    return format;
}

GLenum textarget(GLenum subtarget)
{
    switch(subtarget)
    {
    case GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB:
    case GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB:
    case GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB:
    case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB:
    case GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB:
    case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB:
        return GL_TEXTURE_CUBE_MAP_ARB;
    }
    return subtarget;
}

int formatsize(GLenum format)
{
    switch(format)
    {
    case GL_LUMINANCE:
    case GL_ALPHA: return 1;
    case GL_LUMINANCE_ALPHA: return 2;
    case GL_RGB: return 3;
    case GL_RGBA: return 4;
    default: return 4;
    }
}
