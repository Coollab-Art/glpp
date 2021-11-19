#pragma once

#include <glpp/check_errors.h>
#include <glpp/internal/UniqueHandle.h>

namespace glpp {

namespace internal {
inline GLuint gen_buffer()
{
    GLuint id; // NOLINT
    glGenBuffers(1, &id);
    check_errors();
    return id;
}
inline void del_buffer(GLuint& id)
{
    glDeleteBuffers(1, &id);
    check_errors();
}
} // namespace internal

using UniqueBuffer = internal::UniqueHandle<&internal::gen_buffer, &internal::del_buffer>;

} // namespace glpp