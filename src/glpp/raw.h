#pragma once

#include <glad/gl.h>
#include <glpp/Enums/Channels.h>
#include <glpp/Enums/InternalFormat.h>
#include <glpp/Enums/Interpolation.h>
#include <glpp/Enums/ShaderType.h>
#include <glpp/Enums/TexelDataType.h>
#include <glpp/Enums/TextureKind.h>
#include <glpp/Enums/Wrap.h>

namespace glpp {

template<typename ToType = GLint>
inline ToType raw(Interpolation interpolation)
{
    return static_cast<ToType>(interpolation);
}

inline GLint raw(Wrap wrap)
{
    return static_cast<GLint>(wrap);
}

inline GLenum raw(ShaderType type)
{
    return static_cast<GLenum>(type);
}

inline GLenum raw(TexelDataType type)
{
    return static_cast<GLenum>(type);
}

inline GLenum raw(Channels channels)
{
    return static_cast<GLenum>(channels);
}

inline GLint raw(InternalFormat internal_format)
{
    return static_cast<GLint>(internal_format);
}

inline GLenum raw(TextureKind texture_kind)
{
    return static_cast<GLenum>(texture_kind);
}

} // namespace glpp
