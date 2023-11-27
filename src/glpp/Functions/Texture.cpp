#include "Texture.h"
#include <glpp/check_errors.h>
#include <glpp/internal/assert_is_bound.h>

namespace glpp {

void texture_image_1D(GLuint texture_id, InternalFormat internal_format, GLsizei width, Channels channels, TexelDataType storage_type, const void* data)
{
    internal::assert_is_bound(
        GL_TEXTURE_BINDING_1D, static_cast<GLint>(texture_id),
        "You must bind the texture before setting its image."
    );
    glTexImage1D(GL_TEXTURE_1D, 0, raw(internal_format), width, 0, raw(channels), raw(storage_type), data);
    glpp_check_errors();
}

void texture_image_2D(GLuint texture_id, InternalFormat internal_format, GLsizei width, GLsizei height, Channels channels, TexelDataType storage_type, const void* data)
{
    internal::assert_is_bound(
        GL_TEXTURE_BINDING_2D, static_cast<GLint>(texture_id),
        "You must bind the texture before setting its image."
    );
    glTexImage2D(GL_TEXTURE_2D, 0, raw(internal_format), width, height, 0, raw(channels), raw(storage_type), data);
    glpp_check_errors();
}

void texture_image_3D(GLuint texture_id, InternalFormat internal_format, GLsizei width, GLsizei height, GLsizei depth, Channels channels, TexelDataType storage_type, const void* data)
{
    internal::assert_is_bound(
        GL_TEXTURE_BINDING_3D, static_cast<GLint>(texture_id),
        "You must bind the texture before setting its image."
    );
    glTexImage3D(GL_TEXTURE_3D, 0, raw(internal_format), width, height, depth, 0, raw(channels), raw(storage_type), data);
    glpp_check_errors();
}

void active_texture(GLenum slot_idx)
{
    glActiveTexture(GL_TEXTURE0 + slot_idx);
    glpp_check_errors();
}

} // namespace glpp
