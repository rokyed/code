# inexor::shader

Inexor uses the OpenGL Shader Language (GLSL) for the programmable stage of the rendering pipeline.
To write shaders more conveniently we make the following addition to the main language:

* Use the real standard compliant c++ preprocessor
  * Allows `#include "otherfile.glsl"` directives
  * we use boost::wave for that

* Autodetect uniforms to mirror them on c++-side
  * (and attributes)


# Requires

* C++11
* Boost wave
