#pragma once

#include <glpp/MaybeError.h>
#include <glpp/UniqueHandles/UniqueShader.h>

namespace glpp {
namespace internal {

template<ShaderType type>
class Shader {
public:
    Shader() = default;
    explicit Shader(const char* source_code);
    void       compile(const char* source_code) const;
    MaybeError check_compilation_errors() const;

    GLuint id() const { return _shader.id(); }

private:
    UniqueShader<type> _shader;
};

} // namespace internal

using VertexShader   = internal::Shader<ShaderType::Vertex>;
using FragmentShader = internal::Shader<ShaderType::Fragment>;

} // namespace glpp

#include "Shader.tpp"