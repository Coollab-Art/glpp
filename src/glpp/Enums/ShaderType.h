#pragma once

#include <glad/gl.h>

namespace glpp {

enum class ShaderType : GLenum {
    Vertex                 = GL_VERTEX_SHADER,
    Fragment               = GL_FRAGMENT_SHADER,
    Geometry               = GL_GEOMETRY_SHADER,
    TessellationControl    = GL_TESS_CONTROL_SHADER,
    TessellationEvaluation = GL_TESS_EVALUATION_SHADER,
    Compute                = GL_COMPUTE_SHADER,
};

}