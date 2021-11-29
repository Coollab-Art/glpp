#pragma once

#include <glpp/Enums/Interpolation.h>
#include <glpp/UniqueHandles/UniqueFramebuffer.h>

namespace glpp {

static constexpr GLuint SCREEN_FRAMEBUFFER_ID = 0;

// ---Functions for UniqueFramebuffer---
void bind_framebuffer(const UniqueFramebuffer& framebuffer);
void bind_framebuffer_as_read(const UniqueFramebuffer& framebuffer);
void bind_framebuffer_as_draw(const UniqueFramebuffer& framebuffer);

// ---Functions for raw framebuffer id---
void bind_framebuffer(GLuint framebuffer_id);
void bind_framebuffer_as_read(GLuint framebuffer_id);
void bind_framebuffer_as_draw(GLuint framebuffer_id);

// ---Other

/// Copies the framebuffer currently bound as read to the framebuffer currently bound as draw
void blit_framebuffer(GLint srcX0, GLint srcY0,
                      GLint srcX1, GLint srcY1,
                      GLint dstX0, GLint dstY0,
                      GLint dstX1, GLint dstY1,
                      GLbitfield    mask,
                      Interpolation interpolation);

} // namespace glpp
