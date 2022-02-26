#include "Miscellaneous.h"
#include <glpp/check_errors.h>

namespace glpp {

void viewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
    glViewport(x, y, width, height);
    glpp_check_errors();
}

} // namespace glpp