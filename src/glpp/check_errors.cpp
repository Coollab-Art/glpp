#include "check_errors.h"
#include <glad/glad.h>
#include <iostream>
#include <sstream>

namespace glpp {

static std::function<void(std::string&&)>& error_callback()
{
    static std::function<void(std::string &&)> cb = [](std::string&& error_message) {
        std::cerr << error_message << '\n';
    };
    return cb;
}

void set_error_callback(std::function<void(std::string&&)> callback)
{
    error_callback() = callback;
}

static const char* gl_error_to_string(GLenum err)
{
    switch (err) {
    case GL_NO_ERROR:
        return "GL_NO_ERROR";

    case GL_INVALID_ENUM:
        return "GL_INVALID_ENUM";

    case GL_INVALID_VALUE:
        return "GL_INVALID_VALUE";

    case GL_INVALID_OPERATION:
        return "GL_INVALID_OPERATION";

    case GL_OUT_OF_MEMORY:
        return "GL_OUT_OF_MEMORY";

    case GL_INVALID_FRAMEBUFFER_OPERATION:
        return "GL_INVALID_FRAMEBUFFER_OPERATION";

    default:
        return "UNKNOWN_ERROR_TYPE";
    }
}

void check_errors()
{
#if !defined(NDEBUG)
    check_errors_even_in_release();
#endif
}

void check_errors_even_in_release()
{
    std::stringstream error_message;
    bool              has_found_errors = false;
    GLenum            error; // NOLINT
    while ((error = glGetError()) != GL_NO_ERROR) {
        error_message << "[OpenGL Error] " << gl_error_to_string(error) << '\n';
        has_found_errors = true;
    }
    if (has_found_errors) {
        error_callback()(error_message.str());
    }
}

} // namespace glpp