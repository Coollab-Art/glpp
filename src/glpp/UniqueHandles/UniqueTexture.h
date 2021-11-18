#pragma once

#include <glad/glad.h>

namespace glpp {

class UniqueTexture {
public:
    UniqueTexture()
    {
        glGenTextures(1, &_id);
    }
    ~UniqueTexture()
    {
        glDeleteTextures(1, &_id);
    }
    UniqueTexture(const UniqueTexture&) = delete;
    UniqueTexture& operator=(const UniqueTexture&) = delete;
    UniqueTexture(UniqueTexture&& rhs) noexcept
        : _id{rhs._id}
    {
        rhs._id = 0;
    }
    UniqueTexture& operator=(UniqueTexture&& rhs) noexcept
    {
        if (this != &rhs) {
            glDeleteTextures(1, &_id);
            _id     = rhs._id;
            rhs._id = 0;
        }
        return *this;
    }

    GLuint operator*() const { return _id; }

private:
    GLuint _id;
};

} // namespace glpp