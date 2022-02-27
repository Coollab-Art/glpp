#pragma once

#include <glpp/Enums/Channels.h>
#include <glpp/Enums/InternalFormat.h>
#include <glpp/Enums/Interpolation.h>
#include <glpp/Enums/TexelDataType.h>
#include <glpp/Enums/Wrap.h>
#include <glpp/UniqueHandles/UniqueTexture.h>

namespace glpp {

// ---Functions for UniqueTexture---
template<TextureKind Texture_Kind>
void bind_texture(const internal::UniqueTexture<Texture_Kind>& texture);
template<TextureKind Texture_Kind>
void set_minification_filter(const internal::UniqueTexture<Texture_Kind>& texture, Interpolation interpolation = Interpolation::NearestNeighbour);
template<TextureKind Texture_Kind>
void set_magnification_filter(const internal::UniqueTexture<Texture_Kind>& texture, Interpolation interpolation = Interpolation::Linear);
template<TextureKind Texture_Kind>
void set_wrap(const internal::UniqueTexture<Texture_Kind>& texture, Wrap wrap = Wrap::Repeat);
template<TextureKind Texture_Kind>
void set_horizontal_wrap(const internal::UniqueTexture<Texture_Kind>& texture, Wrap wrap = Wrap::Repeat);
template<TextureKind Texture_Kind>
void set_vertical_wrap(const internal::UniqueTexture<Texture_Kind>& texture, Wrap wrap = Wrap::Repeat);
// template<TextureKind Texture_Kind>
// void set_depth_wrap(const internal::UniqueTexture<Texture_Kind>& texture, Wrap wrap = Wrap::Repeat);

// ---Functions for raw texture id---
template<TextureKind Texture_Kind>
void bind_texture(GLuint texture_id);
template<TextureKind Texture_Kind>
void set_minification_filter(GLuint texture_id, Interpolation interpolation = Interpolation::NearestNeighbour);
template<TextureKind Texture_Kind>
void set_magnification_filter(GLuint texture_id, Interpolation interpolation = Interpolation::Linear);
template<TextureKind Texture_Kind>
void set_wrap(GLuint texture_id, Wrap wrap = Wrap::Repeat);
template<TextureKind Texture_Kind>
void set_horizontal_wrap(GLuint texture_id, Wrap wrap = Wrap::Repeat);
template<TextureKind Texture_Kind>
void set_vertical_wrap(GLuint texture_id, Wrap wrap = Wrap::Repeat);
void texture_image_1D(GLuint texture_id, InternalFormat internal_format, GLsizei width, Channels channels, TexelDataType storage_type, const void* data);
void texture_image_2D(GLuint texture_id, InternalFormat internal_format, GLsizei width, GLsizei height, Channels channels, TexelDataType storage_type, const void* data);
void texture_image_3D(GLuint texture_id, InternalFormat internal_format, GLsizei width, GLsizei height, GLsizei depth, Channels channels, TexelDataType storage_type, const void* data);

// ---
void active_texture(GLenum slot_idx);

} // namespace glpp

#include "Texture.tpp"