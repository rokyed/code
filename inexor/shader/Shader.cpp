
#include "inexor/shader/Shader.hpp"
#include "inexor/engine/glexts.hpp"

namespace inexor {
namespace shader {

static void compile_shader_source(GLenum type, GLuint &obj, std::string source, const char *name, bool msg = true)
{
    obj = glCreateShader_(type);
    // if(versionnotfound) addversionatbeginning(source);
    const GLchar *srcptr = source.c_str();
    glShaderSource_(obj, 1, &srcptr, NULL);
    glCompileShader_(obj);
    GLint success;
    glGetShaderiv_(obj, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        //if(msg) showglslinfo(type, obj, name, parts, numparts);
        glDeleteShader_(obj);
        obj = 0;
    }
    //else if(dbgshader > 1 && msg) showglslinfo(type, obj, name, parts, numparts);
}

bool link_shader(Shader &s, bool msg = true)
{
    if(s.program) return false;
    s.program = s.vsobj && s.psobj ? glCreateProgram_() : 0;

    GLint success = 0;
    if(s.program)
    {
        glAttachShader_(s.program, s.vsobj);
        glAttachShader_(s.program, s.psobj);
        glLinkProgram_(s.program);
        glGetProgramiv_(s.program, GL_LINK_STATUS, &success);
    }
    if(!success)
    {
        if(s.program)
        {
            //if(msg) showglslinfo(GL_FALSE, s.program, s.name);
            glDeleteProgram_(s.program);
            s.program = 0;
        }
        return false;
    }
    return true;
}

bool Shader::parse(const char *source_vert, const char *source_frag)
{
    source_vertex = source_vert;
    source_fragment = source_frag;
    return true;
}

bool Shader::build(bool forcerebuild)
{
    if(!forcerebuild && program) return true;
    if(source_fragment.empty() && source_vertex.empty()) return false; //true ? TODO: verify our preprocessor also checks for emptyness.

    if(forcerebuild && program)
    {
        glDeleteProgram_(program);
        program = 0;
    }

    compile_shader_source(GL_VERTEX_SHADER, vsobj, source_vertex, name.c_str()); //dbgshader || !variantshader);
    compile_shader_source(GL_FRAGMENT_SHADER, psobj, source_fragment, name.c_str());// dbgshader || !variantshader);
    link_shader(*this); // , !variantshader);
    return program != 0;
}

void Shader::use()
{
    glUseProgram_(program);
}

Shader *testshader = nullptr;

} // namespace shader
} // namespace shader
