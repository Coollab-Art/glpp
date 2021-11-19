// namespace glpp {
// namespace internal {

// template<ShaderType type>
// void Shader::compile(const char* source_code)
// {
//     glShaderSource(*_shader, 1, &src, nullptr);
//     check_errors();
//     glCompileShader(*_shader);
//     check_errors();
// #if !defined(NDEBUG)
//     // check_compilation_errors();
// #endif
// }

// // static void validate_shader_module(GLuint id, const std::string& name)
// // {
// //     int result; // NOLINT
// //     glGetShaderiv(id, GL_COMPILE_STATUS, &result);
// //     check_errors();
// //     if (result == GL_FALSE) {
// //         GLsizei length; // NOLINT
// //         glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
// //         check_errors();
// //         std::vector<GLchar> error_message;
// //         error_message.reserve(static_cast<size_t>(length));
// //         glGetShaderInfoLog(id, length, nullptr, error_message.data());
// //         check_errors();
// //         throw std::runtime_error(std::string{name + "\nCompilation failed:\n"} + error_message.data());
// //     }
// // }

// } // namespace internal
// } // namespace glpp