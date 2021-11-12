#pragma once

#include <glad/glad.h>
#include "ShaderKind.h"

namespace glpp {

class UniqueShaderModule {
public:
    explicit UniqueShaderModule(ShaderKind shader_kind);
    ~UniqueShaderModule();
    UniqueShaderModule(const UniqueShaderModule&) = delete;
    UniqueShaderModule& operator=(const UniqueShaderModule&) = delete;
    UniqueShaderModule(UniqueShaderModule&& rhs) noexcept;
    UniqueShaderModule& operator=(UniqueShaderModule&& rhs) noexcept;

    GLuint operator*() const { return _id; }

private:
    GLuint _id;
};

} // namespace glpp