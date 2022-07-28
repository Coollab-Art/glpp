#pragma once

#include <glad/gl.h>

namespace glpp {

enum class TextureKind : GLenum {
    Tex1D = GL_TEXTURE_1D,
    Tex2D = GL_TEXTURE_2D,
    Tex3D = GL_TEXTURE_3D,
};

}