
#pragma once

uniform mat4 hudmatrix;

struct materialsettings
{
    struct textures {
        texture2D diffuse;
        texture2D normal;
        texture2D depth;
    };
    vec2 glare;
    vec2 texgenscroll;
    float parallaxscale;
    vec3 colorize;
};
// TODO: Recognize that some uniforms dont get used and skip them on texture/material.json traversal.

// And yet another comment test */
mat4 function1()
{
   return hudmatrix;
}
