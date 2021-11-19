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
    glShaderSource(*id_, 1, &source_code, nullptr);
    check_errors();
    glCompileShader(*id_);
    check_errors();
#if !defined(NDEBUG)
    check_compilation_errors();
#endif
}

template<ShaderType type>
void Shader<type>::check_compilation_errors()
{
    int result; // NOLINT
    glGetShaderiv(*id_, GL_COMPILE_STATUS, &result);
    check_errors();
    if (result == GL_FALSE) {
        GLsizei length; // NOLINT
        glGetShaderiv(*id_, GL_INFO_LOG_LENGTH, &length);
        check_errors();
        std::vector<GLchar> error_message;
        error_message.reserve(static_cast<size_t>(length));
        glGetShaderInfoLog(*id_, length, nullptr, error_message.data());
        check_errors();
        throw std::runtime_error(std::string{"\nCompilation failed:\n"} + error_message.data());
    }
}

} // namespace internal
} // namespace glpp