#pragma once

#include <glpp/Enums/TextureKind.h>
#include <glpp/check_errors.h>
#include <glpp/internal/UniqueHandle.h>

namespace glpp {

namespace internal {
inline GLuint gen_texture()
{
    GLuint id; // NOLINT
    glGenTextures(1, &id);
    glpp_check_errors();
    return id;
}
inline void del_texture(GLuint& id)
{
    glDeleteTextures(1, &id);
    glpp_check_errors();
}

template<TextureKind Texture_Kind>
using UniqueTexture = internal::UniqueHandle<&internal::gen_texture, &internal::del_texture>;
} // namespace internal

using UniqueTexture1D = internal::UniqueTexture<TextureKind::Tex1D>;
using UniqueTexture2D = internal::UniqueTexture<TextureKind::Tex2D>;
using UniqueTexture3D = internal::UniqueTexture<TextureKind::Tex3D>;

using UniqueTexture = UniqueTexture2D;

} // namespace glpp