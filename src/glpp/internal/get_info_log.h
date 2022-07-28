#pragma once

#include <glad/gl.h>
#include <glpp/MaybeError.h>
#include <vector>

namespace glpp {
namespace internal {

template<void(get_validation)(GLuint, GLint*),
         void(get_log_length)(GLuint, GLsizei*),
         void(get_log)(GLuint, GLsizei, GLchar*)>
MaybeError get_info_log(GLuint id)
{
    GLint result; // NOLINT
    get_validation(id, &result);
    glpp_check_errors();
    if (result == GL_FALSE)
    {
        GLsizei length;
        get_log_length(id, &length);
        glpp_check_errors();
        if (length == 0)
        {
            return MaybeError{"Sorry no error message available"};
        }
        else
        {
            std::vector<GLchar> error_message;
            error_message.reserve(static_cast<size_t>(length));
            get_log(id, length, error_message.data());
            glpp_check_errors();
            return MaybeError{error_message.data()};
        }
    }
    return {};
}

}
} // namespace glpp::internal
