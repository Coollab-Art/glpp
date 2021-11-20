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
    GLint  uniform_location(const char* uniform_name) const;

private:
    UniqueProgram id_;
};

} // namespace glpp
