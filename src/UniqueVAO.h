#pragma once

#include <glad/glad.h>

namespace glpp {

class UniqueVAO {
public:
    UniqueVAO()
    {
        glGenVertexArrays(1, &_id);
    }
    ~UniqueVAO()
    {
        glDeleteVertexArrays(1, &_id);
    }
    UniqueVAO(const UniqueVAO&) = delete;
    UniqueVAO& operator=(const UniqueVAO&) = delete;
    UniqueVAO(UniqueVAO&& rhs) noexcept
        : _id{rhs._id}
    {
        rhs._id = 0;
    }
    UniqueVAO& operator=(UniqueVAO&& rhs) noexcept
    {
        if (this != &rhs) {
            glDeleteVertexArrays(1, &_id);
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
