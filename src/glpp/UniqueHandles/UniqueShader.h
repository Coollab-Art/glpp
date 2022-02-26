#pragma once

#include <glad/glad.h>
#include <glpp/Enums/ShaderType.h>
#include <glpp/check_errors.h>
#include <glpp/internal/UniqueHandle.h>
#include <glpp/raw.h>

namespace glpp {
namespace internal {

template<ShaderType type>
inline GLuint gen_shader()
{
    GLuint id = glCreateShader(raw(type));
    glpp_check_errors();
    return id;
}
inline void del_shader(GLuint& id)
{
    glDeleteShader(id);
    glpp_check_errors();
}

template<ShaderType type>
using UniqueShader = internal::UniqueHandle<&internal::gen_shader<type>, &internal::del_shader>;

} // namespace internal

using UniqueFragmentShader = internal::UniqueShader<ShaderType::Fragment>;
using UniqueVertexShader   = internal::UniqueShader<ShaderType::Vertex>;

} // namespace glpp