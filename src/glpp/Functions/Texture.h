#pragma once

#include <glpp/Enums/Channels.h>
#include <glpp/Enums/InternalFormat.h>
#include <glpp/Enums/Interpolation.h>
#include <glpp/Enums/TexelDataType.h>
#include <glpp/Enums/Wrap.h>
#include <glpp/UniqueHandles/UniqueTexture.h>

namespace glpp {

// ---Functions for UniqueTexture---
void bind_texture(const UniqueTexture& texture);
void set_minification_filter(const UniqueTexture& texture, Interpolation interpolation = Interpolation::NearestNeighbour);
void set_magnification_filter(const UniqueTexture& texture, Interpolation interpolation = Interpolation::Linear);
void set_wrap(const UniqueTexture& texture, Wrap wrap = Wrap::Repeat);
void set_horizontal_wrap(const UniqueTexture& texture, Wrap wrap = Wrap::Repeat);
void set_vertical_wrap(const UniqueTexture& texture, Wrap wrap = Wrap::Repeat);

// ---Functions for raw texture id---
void bind_texture(GLuint texture_id);
void set_minification_filter(GLuint texture_id, Interpolation interpolation = Interpolation::NearestNeighbour);
void set_magnification_filter(GLuint texture_id, Interpolation interpolation = Interpolation::Linear);
void set_wrap(GLuint texture_id, Wrap wrap = Wrap::Repeat);
void set_horizontal_wrap(GLuint texture_id, Wrap wrap = Wrap::Repeat);
void set_vertical_wrap(GLuint texture_id, Wrap wrap = Wrap::Repeat);
void texture_image(GLuint texture_id, InternalFormat internal_format, GLsizei width, GLsizei height, Channels channels, TexelDataType storage_type, const void* data);

} // namespace glpp