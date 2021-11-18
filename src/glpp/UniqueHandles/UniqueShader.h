#pragma once

#include <glad/glad.h>

namespace glpp {

class UniqueShader {
public:
    UniqueShader()
        : _id{glCreateProgram()}
    {
    }
    ~UniqueShader()
    {
        glDeleteProgram(_id);
    }
    UniqueShader(const UniqueShader&) = delete;
    UniqueShader& operator=(const UniqueShader&) = delete;
    UniqueShader(UniqueShader&& rhs) noexcept
        : _id{rhs._id}
    {
        rhs._id = 0;
    }
    UniqueShader& operator=(UniqueShader&& rhs) noexcept
    {
        if (&rhs != this) {
            glDeleteProgram(_id);
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