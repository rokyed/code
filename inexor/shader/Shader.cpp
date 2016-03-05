
#include "inexor/shader/Shader.hpp"
#include "inexor/engine/glexts.hpp"
#include "inexor/engine/engine.hpp"

namespace inexor {
namespace shader {

static void showglslinfo(GLenum type, GLuint obj, const char *name)
{
    GLint length = 0;
    if(type) glGetShaderiv_(obj, GL_INFO_LOG_LENGTH, &length);
    else glGetProgramiv_(obj, GL_INFO_LOG_LENGTH, &length);
    if(length > 1)
    {
        conoutf(CON_ERROR, "GLSL ERROR (%s:%s)", type == GL_VERTEX_SHADER ? "VS" : (type == GL_FRAGMENT_SHADER ? "FS" : "PROG"), name);
        FILE *l = getlogfile(); // temporary code until we get easylogging
        if(l)
        {
            GLchar *log = new GLchar[length];
            if(type) glGetShaderInfoLog_(obj, length, &length, log);
            else glGetProgramInfoLog_(obj, length, &length, log);
            fprintf(l, "%s\n", log);
            delete[] log;
        }
    }
}

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
        if(msg) showglslinfo(type, obj, name);
        glDeleteShader_(obj);
        obj = 0;
    }
    //else if(dbgshader > 1 && msg) showglslinfo(type, obj, name);
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
            if(msg) showglslinfo(GL_FALSE, s.program, s.name.c_str());
            glDeleteProgram_(s.program);
            s.program = 0;
        }
        return false;
    }
    return true;
}

bool Shader::parse(const std::string &source_vert, const std::string &source_frag)
{
    source_vertex = source_vert;
    source_fragment = source_frag;
    return true;
}

bool Shader::build(bool forcerebuild)
{
    if(!forcerebuild && program) return true;
    if(source_fragment.empty() && source_vertex.empty()) return false; //TODO: verify our preprocessor also checks for emptyness.

    if(forcerebuild && program)
    {
        glDeleteProgram_(program);
        program = 0;
    }

    compile_shader_source(GL_VERTEX_SHADER, vsobj, source_vertex, name.c_str()); //dbgshader || !variantshader);
    compile_shader_source(GL_FRAGMENT_SHADER, psobj, source_fragment, name.c_str());// dbgshader || !variantshader);
    link_shader(*this); // , !variantshader);

    isbuilt = program != 0;
    return isbuilt;
}

void Shader::use()
{
    glUseProgram_(program);
}

Shader *testshader = nullptr;

} // namespace shader
} // namespace inexor
