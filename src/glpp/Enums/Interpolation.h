#pragma once

#include <glad/glad.h>

namespace glpp {

enum class Interpolation : GLint {
    NearestNeighbour = GL_NEAREST,
    Linear           = GL_LINEAR,
};

} // namespace glpp
