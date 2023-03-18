#include <glpp/internal/get_info_log.h>

namespace glpp {
namespace internal {

template<ShaderType type>
Shader<type>::Shader(const char* source_code)
{
    compile(source_code);
}

template<ShaderType type>
void Shader<type>::compile(const char* source_code) const
{
    glShaderSource(*id_, 1, &source_code, nullptr);
    glpp_check_errors();
    glCompileShader(*id_);
    glpp_check_errors();
}

inline void get_shader_validation(GLuint id, GLint* result)
{
    glGetShaderiv(id, GL_COMPILE_STATUS, result);
}
inline void get_shader_log_length(GLuint id, GLsizei* length)
{
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, length);
}
inline void get_shader_log(GLuint id, GLsizei length, GLchar* message)
{
    glGetShaderInfoLog(id, length, nullptr, message);
}

template<ShaderType type>
MaybeError Shader<type>::check_compilation_errors() const
{
    return internal::get_info_log<&get_shader_validation, &get_shader_log_length, &get_shader_log>(*id_);
}

}
} // namespace glpp::internal