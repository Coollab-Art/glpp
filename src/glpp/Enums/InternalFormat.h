#pragma once

#include <glad/glad.h>

namespace glpp {

enum class InternalFormat : GLint {
    R              = GL_RED,
    RG             = GL_RG,
    RGB            = GL_RGB,
    RGBA           = GL_RGBA,
    DepthComponent = GL_DEPTH_COMPONENT,
    DepthStencil   = GL_DEPTH_STENCIL,
};

} // namespace glpp
