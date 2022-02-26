#include "Texture.h"
#include <glpp/check_errors.h>
#include <glpp/internal/assert_is_bound.h>
#include <glpp/raw.h>

namespace glpp {

// ---
// --- Functions for UniqueTexture
// ---

void bind_texture(const UniqueTexture& texture)
{
    bind_texture(*texture);
}

void set_minification_filter(const UniqueTexture& texture, Interpolation interpolation)
{
    set_minification_filter(*texture, interpolation);
}

void set_magnification_filter(const UniqueTexture& texture, Interpolation interpolation)
{
    set_magnification_filter(*texture, interpolation);
}

void set_wrap(const UniqueTexture& texture, Wrap wrap)
{
    set_wrap(*texture, wrap);
}

void set_horizontal_wrap(const UniqueTexture& texture, Wrap wrap)
{
    set_horizontal_wrap(*texture, wrap);
}

void set_vertical_wrap(const UniqueTexture& texture, Wrap wrap)
{
    set_vertical_wrap(*texture, wrap);
}

// ---
// --- Functions for raw texture id
// ---

void bind_texture(GLuint texture_id)
{
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glpp_check_errors();
}

void set_minification_filter(GLuint texture_id, Interpolation interpolation)
{
    internal::assert_is_bound(GL_TEXTURE_BINDING_2D, static_cast<GLint>(texture_id),
                              "You must bind the texture before setting its minification filter");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, raw(interpolation));
    glpp_check_errors();
}

void set_magnification_filter(GLuint texture_id, Interpolation interpolation)
{
    internal::assert_is_bound(GL_TEXTURE_BINDING_2D, static_cast<GLint>(texture_id),
                              "You must bind the texture before setting its magnification filter");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, raw(interpolation));
    glpp_check_errors();
}

void set_wrap(GLuint texture_id, Wrap wrap)
{
    set_horizontal_wrap(texture_id, wrap);
    set_vertical_wrap(texture_id, wrap);
}

void set_horizontal_wrap(GLuint texture_id, Wrap wrap)
{
    internal::assert_is_bound(GL_TEXTURE_BINDING_2D, static_cast<GLint>(texture_id),
                              "You must bind the texture before setting its wrap mode");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, raw(wrap));
    glpp_check_errors();
}

void set_vertical_wrap(GLuint texture_id, Wrap wrap)
{
    internal::assert_is_bound(GL_TEXTURE_BINDING_2D, static_cast<GLint>(texture_id),
                              "You must bind the texture before setting its wrap mode");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, raw(wrap));
    glpp_check_errors();
}

void texture_image(GLuint texture_id, InternalFormat internal_format, GLsizei width, GLsizei height, Channels channels, TexelDataType storage_type, const void* data)
{
    internal::assert_is_bound(GL_TEXTURE_BINDING_2D, static_cast<GLint>(texture_id),
                              "You must bind the texture before setting its image");
    glTexImage2D(GL_TEXTURE_2D, 0, raw(internal_format), width, height, 0, raw(channels), raw(storage_type), data);
    glpp_check_errors();
}

// ---

void active_texture(GLenum slot_idx)
{
    glActiveTexture(GL_TEXTURE0 + slot_idx);
    glpp_check_errors();
}

} // namespace glpp
