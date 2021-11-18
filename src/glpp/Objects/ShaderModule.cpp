#include "ShaderModule.h"
#include <glpp/check_errors.h>
#include <stdexcept>
#include <vector>


namespace glpp {

static void validate_shader_module(GLuint id, const std::string& name)
{
    int result; // NOLINT
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    check_errors();
    if (result == GL_FALSE) {
        GLsizei length; // NOLINT
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        check_errors();
        std::vector<GLchar> error_message;
        error_message.reserve(static_cast<size_t>(length));
        glGetShaderInfoLog(id, length, nullptr, error_message.data());
        check_errors();
        throw std::runtime_error(std::string{name + "\nCompilation failed:\n"} + error_message.data());
    }
}

static void compile_shader_module(GLuint id, const ShaderDescription& desc)
{
    const char* src = desc.source_code.c_str();
    glShaderSource(id, 1, &src, nullptr);
    check_errors();
    glCompileShader(id);
    check_errors();
    validate_shader_module(id, desc.name);
}

ShaderModule::ShaderModule(const ShaderDescription& desc)
    : _shader_module{desc.kind}
{
    compile_shader_module(*_shader_module, desc);
}

} // namespace glpp