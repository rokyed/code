
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
    std::string name; // TODO move to hashtable (?)

    /// The Values of the parameter
    union
    {
        //float int ..;
    } values;

    /// How often this parameter was changed.
    int version;

    /// The OpenGL internal binding location, used for GPU-CPU communication (or mapping of the 
    GLint location;

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

    /// Whether this OpenGL Shader Program is compiled or not (it gets parsed, then built, then used).
    bool isbuilt;

    std::vector<ShaderParameter> uniforms;
    // std::vector<ShaderTexture>;

    /// The OpenGL ID of the object files (intermediates of the build, unlinked binary).
    GLuint vsobj, psobj;

    /// Main constructor, does not give a working shader, you need to parse() the source, build() and use() it.
    Shader(std::string &shadername) : name(shadername) {}

    /// Parse the specific input source strings for the shader.
    /// Note, we do expect the source to be ........................................................
    bool parse(const std::string &source_vert, const std::string &source_frag);

    /// Compile and link this shader, outputs warnings in case something went wrong.
    /// TODO: exceptions
    /// @return isbuilt, if it's a valid shader returns true.
    bool build(bool forcerebuild = false);

    /// Use this Shader for the next rendering calls.
    /// In order to do any binding of uniforms OpenGL requires to use(/"bind") the specific shader as well before.
    void use();
};

extern Shader *testshader;

} // namespace shader
} // namespace inexor
