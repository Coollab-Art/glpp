#pragma once

#include <glpp/MaybeError.h>
#include <glpp/UniqueHandles/UniqueProgram.h>

namespace glpp {

class Program {
public:
    void       attach_shader(GLuint shader_id) const;
    void       link() const;
    MaybeError check_linking_errors() const;

    GLuint operator*() const { return *id_; }
    void   use() const;
    GLint  compute_uniform_location(const char* uniform_name) const;
    void   set_uniform(GLint uniform_location, int v) const;
    void   set_uniform(GLint uniform_location, unsigned int v) const;
    void   set_uniform(GLint uniform_location, bool v) const;
    void   set_uniform(GLint uniform_location, float v) const;
    void   set_uniform(GLint uniform_location, float x, float y) const;
    void   set_uniform(GLint uniform_location, float x, float y, float z) const;
    void   set_uniform(GLint uniform_location, float x, float y, float z, float w) const;
    void   set_uniform_mat2(GLint uniform_location, const float m[4]) const;
    void   set_uniform_mat3(GLint uniform_location, const float m[9]) const;
    void   set_uniform_mat4(GLint uniform_location, const float m[16]) const;

private:
    UniqueProgram id_;
};

} // namespace glpp
