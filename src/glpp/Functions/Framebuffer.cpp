#include "Framebuffer.h"
#include <glpp/raw.h>

namespace glpp {

// ---
// --- Functions for UniqueFramebuffer
// ---

void bind_framebuffer(const UniqueFramebuffer& framebuffer)
{
    bind_framebuffer(framebuffer.id());
}

void bind_framebuffer_as_read(const UniqueFramebuffer& framebuffer)
{
    bind_framebuffer_as_read(framebuffer.id());
}

void bind_framebuffer_as_draw(const UniqueFramebuffer& framebuffer)
{
    bind_framebuffer_as_draw(framebuffer.id());
}

// ---
// --- Functions for raw framebuffer id
// ---

void bind_framebuffer(GLuint framebuffer_id)
{
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer_id);
    glpp_check_errors();
}

void bind_framebuffer_as_read(GLuint framebuffer_id)
{
    glBindFramebuffer(GL_READ_FRAMEBUFFER, framebuffer_id);
    glpp_check_errors();
}

void bind_framebuffer_as_draw(GLuint framebuffer_id)
{
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, framebuffer_id);
    glpp_check_errors();
}

// ---
// --- Other
// ---

void blit_framebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, Interpolation interpolation)
{
    glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, raw<GLenum>(interpolation));
    glpp_check_errors();
}

GLuint get_current_read_framebuffer()
{
    GLint _id; // NOLINT
    glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &_id);
    return static_cast<GLuint>(_id);
}

GLuint get_current_draw_framebuffer()
{
    GLint _id; // NOLINT
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &_id);
    return static_cast<GLuint>(_id);
}

} // namespace glpp