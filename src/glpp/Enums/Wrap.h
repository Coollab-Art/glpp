#pragma once

#include <glad/gl.h>

namespace glpp {

enum class Wrap : GLint {
    Repeat         = GL_REPEAT,
    MirroredRepeat = GL_MIRRORED_REPEAT,
    ClampToEdge    = GL_CLAMP_TO_EDGE,
    ClampToBorder  = GL_CLAMP_TO_BORDER,
};

} // namespace glpp
