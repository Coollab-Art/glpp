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
#else
    (void)pname;         // Silence the "unused parameter" warning
    (void)id;            // Silence the "unused parameter" warning
    (void)error_message; // Silence the "unused parameter" warning
#endif
}

} // namespace internal
} // namespace glpp
