#include "assert_is_bound.h"
#include <cassert>

namespace glpp {
namespace internal {

void assert_is_bound(GLenum pname, GLint id, const char* error_message)
{
#if !defined(NDEBUG)
    GLint current_id; // NOLINT
    glGetIntegerv(pname, &current_id);
    assert(current_id == id && error_message);
#endif
}

} // namespace internal
} // namespace glpp
