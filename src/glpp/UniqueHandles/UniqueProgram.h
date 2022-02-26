#pragma once

#include <glpp/check_errors.h>
#include <glpp/internal/UniqueHandle.h>

namespace glpp {

namespace internal {
inline GLuint gen_program()
{
    GLuint id = glCreateProgram();
    glpp_check_errors();
    return id;
}
inline void del_program(GLuint& id)
{
    glDeleteProgram(id);
    glpp_check_errors();
}
} // namespace internal

using UniqueProgram = internal::UniqueHandle<&internal::gen_program, &internal::del_program>;

} // namespace glpp