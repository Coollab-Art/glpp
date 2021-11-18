#pragma once

#include <glad/glad.h>

namespace glpp {

class UniqueBuffer {
public:
    UniqueBuffer()
    {
        glGenBuffers(1, &_id);
    }
    ~UniqueBuffer()
    {
        glDeleteBuffers(1, &_id);
    }
    UniqueBuffer(const UniqueBuffer&) = delete;
    UniqueBuffer& operator=(const UniqueBuffer&) = delete;
    UniqueBuffer(UniqueBuffer&& rhs) noexcept
        : _id{rhs._id}
    {
        rhs._id = 0;
    }
    UniqueBuffer& operator=(UniqueBuffer&& rhs) noexcept
    {
        if (this != &rhs) {
            glDeleteBuffers(1, &_id);
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