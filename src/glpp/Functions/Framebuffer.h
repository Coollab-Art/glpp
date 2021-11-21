#pragma once

#include <glpp/UniqueHandles/UniqueFramebuffer.h>

namespace glpp {

class Framebuffer {
public:
    GLuint operator*() const { return *id_; }
    void   bind() const;

private:
    UniqueFramebuffer id_;
};

} // namespace glpp
