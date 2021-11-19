#pragma once

#include <glpp/check_errors.h>
#include <glpp/internal/UniqueHandle.h>

namespace glpp {

namespace internal {
inline GLuint gen_vertex_array()
{
    GLuint id; // NOLINT
    glGenVertexArrays(1, &id);
    check_errors();
    return id;
}
inline void del_vertex_array(GLuint& id)
{
    glDeleteVertexArrays(1, &id);
    check_errors();
}
} // namespace internal

using UniqueVertexArray = internal::UniqueHandle<&internal::gen_vertex_array, &internal::del_vertex_array>;

} // namespace glpp