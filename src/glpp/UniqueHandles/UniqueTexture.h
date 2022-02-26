#pragma once

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
} // namespace internal

using UniqueTexture = internal::UniqueHandle<&internal::gen_texture, &internal::del_texture>;

} // namespace glpp