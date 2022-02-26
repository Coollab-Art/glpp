#pragma once

#include <glpp/check_errors.h>
#include <glpp/internal/UniqueHandle.h>

namespace glpp {

namespace internal {
inline GLuint gen_framebuffer()
{
    GLuint id; // NOLINT
    glGenFramebuffers(1, &id);
    glpp_check_errors();
    return id;
}
inline void def_framebuffer(GLuint& id)
{
    glDeleteFramebuffers(1, &id);
    glpp_check_errors();
}
} // namespace internal

using UniqueFramebuffer = internal::UniqueHandle<&internal::gen_framebuffer, &internal::def_framebuffer>;

} // namespace glpp