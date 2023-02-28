#pragma once

#include <glpp/check_errors.h>
#include <glpp/internal/UniqueHandle.h>

namespace glpp {

namespace internal {
inline GLuint gen_renderbuffer()
{
    GLuint id; // NOLINT
    glGenRenderbuffers(1, &id);
    glpp_check_errors();
    return id;
}
inline void del_renderbuffer(GLuint& id)
{
    glDeleteRenderbuffers(1, &id);
    glpp_check_errors();
}
} // namespace internal

using UniqueRenderbuffer = internal::UniqueHandle<&internal::gen_renderbuffer, &internal::del_renderbuffer>;

} // namespace glpp