#pragma once

#include <glad/glad.h>

namespace glpp {

enum class Channels : GLenum {
    R              = GL_RED,
    RG             = GL_RG,
    RGB            = GL_RGB,
    BGR            = GL_BGR,
    RGBA           = GL_RGBA,
    BGRA           = GL_BGRA,
    R_Integer      = GL_RED_INTEGER,
    RG_Integer     = GL_RG_INTEGER,
    RGB_Integer    = GL_RGB_INTEGER,
    BGR_Integer    = GL_BGR_INTEGER,
    RGBA_Integer   = GL_RGBA_INTEGER,
    BGRA_Integer   = GL_BGRA_INTEGER,
    StencilIndex   = GL_STENCIL_INDEX,
    DepthComponent = GL_DEPTH_COMPONENT,
    DepthStencil   = GL_DEPTH_STENCIL,
};

} // namespace glpp
