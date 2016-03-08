#pragma once

#include "inexor/shader/Shader.hpp"

namespace inexor {
namespace shader {

enum DATA_TYPES_NUMBERS
{
    GLSL_FLOAT = 0,
    GLSL_INT,
    GLSL_UINT,
    GLSL_BOOL,
    GLSL_DOUBLE,

    GLSL_VEC2,
    GLSL_VEC3,
    GLSL_VEC4,

    GLSL_MAT2,              /// Matrix 2 rows, 2 columns
    GLSL_MAT3,
    GLSL_MAT4,

    GLSL_ARRAY,

    GLSL_VERTEX_SHADER_ONLY /// equals an attribute
};

enum DATA_TYPES_TEXTURES
{
    GLSL_TEXTURE1D,
    GLSL_TEXTURE2D,         // sampler{+evtl"2D"}
    GLSL_TEXTURE3D,
    GLSL_MS_TEXTURE2D,      // Multisample 2D texture (multiple samples per pixel)

                            // array versions of the first 4..

    GLSL_TEXTURE_CUBEMAP,
    GLSL_TEXTURE_BUFFER,    // A buffer object, raw unformatted memory.
    GLSL_TEXTURE_RECTANGLE, // single 2D Texture without mipmaps. {f/i/ui/d}sampler2D{Rect/RectShadow}

    GLSL_IMAGE_iwas
};

struct datarepresentation
{
    int type;               /// The data format of the GLSL uniform variable, one of DATA_TYPES or DATA_TYPES_TEXTURES.
    const char *glslsource; /// The according GLSL source code string for that data type, e.g. "int" for DATA_INTEGER.
    // rapidjson::Value 
};


extern std::string preprocessShader(const std::string &filename, const std::string &source); // , const std::vector<std::string> &includepaths);

} // namespace shader
} // namespace inexor
extern void parseuniformstruct(std::string source);
