#include "Texture.h"
#include <glpp/check_errors.h>

namespace glpp {

void active_texture(GLenum slot_idx)
{
    glActiveTexture(GL_TEXTURE0 + slot_idx);
    glpp_check_errors();
}

} // namespace glpp
