#pragma once

#include <glad/gl.h>

namespace glpp {
namespace internal {

/// Raises an assert if the object bound at pname is not id
/// pname is an enum from this list: http://docs.gl/gl4/glGet
void assert_is_bound(GLenum pname, GLint id, const char* error_message);

}
} // namespace glpp::internal
