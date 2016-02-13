#include "shader_preprocessor_globals.frag"

attribute vec4 vvertex, vcolor;
attribute vec2 vtexcoord0;
uniform mat4 hudmatrix;
varying vec2 texcoord0;
varying vec4 color;

// Does this comment work?
/*
i think so!
*/
void main(void)
{
    gl_Position = hudmatrix * vvertex;
    texcoord0 = vtexcoord0;
    color = vcolor;
}
