
#pragma once

#include <SDL.h>
#include <SDL_opengl.h>

#include <string>
#include <vector>

namespace inexor {
namespace shader {

/// An uniform 
struct ShaderParameter
{
    /// The parameter name, used to access the param.
    std::string name; // TODO move to hashtable

    /// The Values of the parameter
    union
    {
        //float int ..;
    } values;

    /// How often this parameter was changed.
    int version;

    /// The OpenGL internal binding location, used for GPU-CPU communication (or mapping of the 

    /// Send info about changes to the gpu
    void change();
};

/// Encolapses the Core 
struct Shader
{
    /// The name of the shader used to access it.. TODO move to hashtable?
    std::string name;

    /// One of the above defined types, TODO, no types needed yet.
    int type;

    /// The raw input code strings of the shader (already preprocessed).
    std::string source_vertex, source_fragment;

    /// The OpenGL ID of this shader.
    GLuint program;

    /// Whether this OpenGL Shader Program is compiled or not.
    bool iscompiled;

    std::vector<ShaderParameter> uniforms;
    // std::vector<ShaderTexture>;

    /// The OpenGL ID of the object files (intermediates of the build, unlinked binary).
    GLuint vsobj, psobj;

    /// Main constructor from the given source.
    /// @note Does not build the shader, so calling build() is needed in order to use() it.
    bool parse(const char *source_vert, const char *source_frag);

    bool build(bool forcerebuild = false);

    void use();

};

extern Shader *testshader;

} // namespace shader
} // namespace inexor
