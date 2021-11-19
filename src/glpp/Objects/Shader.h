#pragma once

#include <glpp/UniqueHandles/UniqueShader.h>

namespace glpp {
namespace internal {

template<ShaderType type>
class Shader {
public:
    Shader() = default;
    explicit Shader(const char* source_code);
    GLuint operator*() const { return *id_; }

    void compile(const char* source_code);
    void check_compilation_errors();

private:
    UniqueShader<type> id_;
};

} // namespace internal

using VertexShader   = internal::Shader<ShaderType::Vertex>;
using FragmentShader = internal::Shader<ShaderType::Fragment>;

} // namespace glpp

#include "Shader.tpp"