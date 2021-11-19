#pragma once

#include <glpp/UniqueHandles/UniqueShader.h>

namespace glpp {
namespace internal {

template<ShaderType type>
class Shader {
public:
    Shader() = default;
    Shader(const char* source_code);
    GLuint operator*() const { return *_shader; }

    void compile(const char* source_code);
    // void check_compilation_errors();

private:
    UniqueShader<type> _shader;
};

} // namespace internal

using VertexShader   = internal::Shader<ShaderType::Vertex>;
using FragmentShader = internal::Shader<ShaderType::Fragment>;

} // namespace glpp

#include "Shader.tpp"
namespace glpp {
namespace internal {

template<ShaderType type>
Shader<type>::Shader(const char* source_code)
{
    compile(source_code);
}

template<ShaderType type>
void Shader<type>::compile(const char* source_code)
{
    glShaderSource(*_shader, 1, &source_code, nullptr);
    check_errors();
    glCompileShader(*_shader);
    check_errors();
#if !defined(NDEBUG)
    // check_compilation_errors();
#endif
}

// static void validate_shader_module(GLuint id, const std::string& name)
// {
//     int result; // NOLINT
//     glGetShaderiv(id, GL_COMPILE_STATUS, &result);
//     check_errors();
//     if (result == GL_FALSE) {
//         GLsizei length; // NOLINT
//         glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
//         check_errors();
//         std::vector<GLchar> error_message;
//         error_message.reserve(static_cast<size_t>(length));
//         glGetShaderInfoLog(id, length, nullptr, error_message.data());
//         check_errors();
//         throw std::runtime_error(std::string{name + "\nCompilation failed:\n"} + error_message.data());
//     }
// }

} // namespace internal
} // namespace glpp