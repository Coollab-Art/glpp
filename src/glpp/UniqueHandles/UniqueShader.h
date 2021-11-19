#pragma once

#include <glpp/check_errors.h>
#include <glpp/internal/UniqueHandle.h>

namespace glpp {

namespace internal {
inline GLuint gen_program()
{
    GLuint id = glCreateProgram();
    check_errors();
    return id;
}
inline void del_program(GLuint& id)
{
    glDeleteProgram(id);
    check_errors();
}
} // namespace internal

using UniqueShader = internal::UniqueHandle<&internal::gen_program, &internal::del_program>;

} // namespace glpp