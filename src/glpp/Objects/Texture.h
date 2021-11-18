#pragma once

#include <glpp/Enums/Interpolation.h>
#include <glpp/Enums/Wrap.h>
#include <glpp/UniqueHandles/UniqueTexture.h>

namespace glpp {

class Texture {
public:
    Texture(Interpolation minification_filter  = Interpolation::NearestNeighbour,
            Interpolation magnification_filter = Interpolation::Linear,
            Wrap          horizontal_wrap      = Wrap::Repeat,
            Wrap          vertical_wrap        = Wrap::Repeat);

    GLuint id() const { return *id_; }

    void bind() const;
    void set_minification_filter(Interpolation interpolation = Interpolation::NearestNeighbour) const;
    void set_magnification_filter(Interpolation interpolation = Interpolation::Linear) const;
    void set_wrap(Wrap wrap = Wrap::Repeat) const;
    void set_horizontal_wrap(Wrap wrap = Wrap::Repeat) const;
    void set_vertical_wrap(Wrap wrap = Wrap::Repeat) const;

private:
    UniqueTexture id_;
};

} // namespace glpp