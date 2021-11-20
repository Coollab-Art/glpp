#include "assert_is_bound.h"
#include <cassert>
#include <iostream>

namespace glpp {
namespace internal {

void assert_is_bound(GLenum pname, GLint id, const char* error_message)
{
#if !defined(NDEBUG)
    GLint current_id; // NOLINT
    glGetIntegerv(pname, &current_id);
    if (current_id != id) {
        std::cerr << error_message << '\n';
        assert(false);
    }
#endif
}

} // namespace internal
} // namespace glpp
