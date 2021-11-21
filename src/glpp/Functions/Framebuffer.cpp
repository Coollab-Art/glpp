#include "Framebuffer.h"

namespace glpp {

void Framebuffer::bind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, *id_);
    check_errors();
    // GLDebug(glViewport(0, 0, static_cast<GLsizei>(width()), static_cast<GLsizei>(height()))); // Only usefull if we plan on using this frame buffer at a different resolution than the screen's
}

} // namespace glpp