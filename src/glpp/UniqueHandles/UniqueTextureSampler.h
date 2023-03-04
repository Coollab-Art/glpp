#pragma once

#include <glpp/check_errors.h>
#include <glpp/internal/UniqueHandle.h>

namespace glpp {

inline auto gen_sampler() -> GLuint
{
    GLuint id; // NOLINT
    glGenSamplers(1, &id);
    glpp_check_errors();
    return id;
}
inline void del_sampler(GLuint& id)
{
    glDeleteSamplers(1, &id);
    glpp_check_errors();
}

using UniqueTextureSampler = internal::UniqueHandle<&gen_sampler, &del_sampler>;

} // namespace glpp