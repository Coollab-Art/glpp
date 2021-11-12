#include "check_errors.h"
#include <glad/glad.h>
#include <cassert>
#include <iostream>

namespace glpp {

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

static bool check_for_errors(const char* filename, int line)
{
    GLenum error; // NOLINT
    bool   has_found_errors = false;
    while ((error = glGetError()) != GL_NO_ERROR) {
        std::cerr << "[OpenGL Error] " << gl_error_to_string(error) << " : " << filename << ' ' << line << '\n';
        has_found_errors = true;
    }
    return has_found_errors;
}

void check_errors()
{
#if !defined(NDEBUG)
    check_errors_even_in_release();
#endif
}

void check_errors_even_in_release()
{
    assert(!check_for_errors(__FILE__, __LINE__));
}

} // namespace glpp