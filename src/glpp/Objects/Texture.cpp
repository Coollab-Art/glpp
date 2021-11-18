#include "Texture.h"
#include <glpp/check_errors.h>
#include <glpp/internal/assert_is_bound.h>
#include <glpp/raw.h>

namespace glpp {

Texture::Texture(Interpolation minification_filter,
                 Interpolation magnification_filter,
                 Wrap          horizontal_wrap,
                 Wrap          vertical_wrap)
{
    bind();
    set_minification_filter(minification_filter);
    set_magnification_filter(magnification_filter);
    set_horizontal_wrap(horizontal_wrap);
    set_vertical_wrap(vertical_wrap);
}

void Texture::bind() const
{
    glBindTexture(GL_TEXTURE_2D, *id_);
    check_errors();
}

void Texture::set_minification_filter(Interpolation interpolation) const
{
    internal::assert_is_bound(GL_TEXTURE_BINDING_2D, *id_,
                              "You must bind the texture before setting the minification filter");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, raw(interpolation));
    check_errors();
}

void Texture::set_magnification_filter(Interpolation interpolation) const
{
    internal::assert_is_bound(GL_TEXTURE_BINDING_2D, *id_,
                              "You must bind the texture before setting the magnification filter");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, raw(interpolation));
    check_errors();
}

void Texture::set_wrap(Wrap wrap) const
{
    set_horizontal_wrap(wrap);
    set_vertical_wrap(wrap);
}

void Texture::set_horizontal_wrap(Wrap wrap) const
{
    internal::assert_is_bound(GL_TEXTURE_BINDING_2D, *id_,
                              "You must bind the texture before setting the wrap mode");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, raw(wrap));
    check_errors();
}

void Texture::set_vertical_wrap(Wrap wrap) const
{
    internal::assert_is_bound(GL_TEXTURE_BINDING_2D, *id_,
                              "You must bind the texture before setting the wrap mode");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, raw(wrap));
    check_errors();
}

} // namespace glpp
