#include <glpp/check_errors.h>
#include <glpp/internal/assert_is_bound.h>
#include <glpp/raw.h>

namespace glpp {

// ---
// --- Functions for UniqueTexture
// ---

template<TextureKind Texture_Kind>
void bind_texture(const internal::UniqueTexture<Texture_Kind>& texture)
{
    bind_texture<Texture_Kind>(*texture);
}

template<TextureKind Texture_Kind>
void set_minification_filter(const internal::UniqueTexture<Texture_Kind>& texture, Interpolation interpolation)
{
    set_minification_filter<Texture_Kind>(*texture, interpolation);
}

template<TextureKind Texture_Kind>
void set_magnification_filter(const internal::UniqueTexture<Texture_Kind>& texture, Interpolation interpolation)
{
    set_magnification_filter<Texture_Kind>(*texture, interpolation);
}

template<TextureKind Texture_Kind>
void set_wrap(const internal::UniqueTexture<Texture_Kind>& texture, Wrap wrap)
{
    set_wrap<Texture_Kind>(*texture, wrap);
}

template<TextureKind Texture_Kind>
void set_wrap_s(const internal::UniqueTexture<Texture_Kind>& texture, Wrap wrap)
{
    set_wrap_s<Texture_Kind>(*texture, wrap);
}

template<TextureKind Texture_Kind>
void set_wrap_t(const internal::UniqueTexture<Texture_Kind>& texture, Wrap wrap)
{
    set_wrap_t<Texture_Kind>(*texture, wrap);
}

template<TextureKind Texture_Kind>
void set_wrap_r(const internal::UniqueTexture<Texture_Kind>& texture, Wrap wrap)
{
    set_wrap_r<Texture_Kind>(*texture, wrap);
}

// ---
// --- Functions for raw texture id
// ---

namespace internal {

template<TextureKind Texture_Kind>
GLenum texture_binding()
{
    static_assert(Texture_Kind == TextureKind::Tex1D ||
                      Texture_Kind == TextureKind::Tex2D ||
                      Texture_Kind == TextureKind::Tex3D,
                  "Unknown texture kind");
    if constexpr (Texture_Kind == TextureKind::Tex1D) {
        return GL_TEXTURE_BINDING_1D;
    }
    else if constexpr (Texture_Kind == TextureKind::Tex2D) {
        return GL_TEXTURE_BINDING_2D;
    }
    else if constexpr (Texture_Kind == TextureKind::Tex3D) {
        return GL_TEXTURE_BINDING_3D;
    }
    else {
        return GL_TEXTURE_BINDING_1D; // Should never happen. This is prevented by the static_assert.
    }
}

template<TextureKind Texture_Kind>
void assert_texture_is_bound(GLuint texture_id, const char* error_message)
{
    internal::assert_is_bound(texture_binding<Texture_Kind>(), static_cast<GLint>(texture_id), error_message);
}

template<TextureKind Texture_Kind>
constexpr int texture_dimension()
{
    static_assert(Texture_Kind == TextureKind::Tex1D ||
                      Texture_Kind == TextureKind::Tex2D ||
                      Texture_Kind == TextureKind::Tex3D,
                  "Unknown texture kind");
    if constexpr (Texture_Kind == TextureKind::Tex1D) {
        return 1;
    }
    else if constexpr (Texture_Kind == TextureKind::Tex2D) {
        return 2;
    }
    else if constexpr (Texture_Kind == TextureKind::Tex3D) {
        return 3;
    }
    else {
        return 0; // Should never happen. This is prevented by the static_assert.
    }
}

} // namespace internal

template<TextureKind Texture_Kind>
void bind_texture(GLuint texture_id)
{
    glBindTexture(raw(Texture_Kind), texture_id);
    glpp_check_errors();
}

template<TextureKind Texture_Kind>
void set_minification_filter(GLuint texture_id, Interpolation interpolation)
{
    internal::assert_texture_is_bound<Texture_Kind>(texture_id,
                                                    "You must bind the texture before setting its minification filter");
    glTexParameteri(raw(Texture_Kind), GL_TEXTURE_MIN_FILTER, raw(interpolation));
    glpp_check_errors();
}

template<TextureKind Texture_Kind>
void set_magnification_filter(GLuint texture_id, Interpolation interpolation)
{
    internal::assert_texture_is_bound<Texture_Kind>(texture_id,
                                                    "You must bind the texture before setting its magnification filter");
    glTexParameteri(raw(Texture_Kind), GL_TEXTURE_MAG_FILTER, raw(interpolation));
    glpp_check_errors();
}

template<TextureKind Texture_Kind>
void set_wrap(GLuint texture_id, Wrap wrap)
{
    set_wrap_s<Texture_Kind>(texture_id, wrap);
    if constexpr (internal::texture_dimension<Texture_Kind>() >= 2) {
        set_wrap_t<Texture_Kind>(texture_id, wrap);
        if constexpr (internal::texture_dimension<Texture_Kind>() >= 3) {
            set_wrap_r<Texture_Kind>(texture_id, wrap);
        }
    }
}

template<TextureKind Texture_Kind>
void set_wrap_s(GLuint texture_id, Wrap wrap)
{
    internal::assert_texture_is_bound<Texture_Kind>(texture_id,
                                                    "You must bind the texture before setting its wrap mode");
    glTexParameteri(raw(Texture_Kind), GL_TEXTURE_WRAP_S, raw(wrap));
    glpp_check_errors();
}

template<TextureKind Texture_Kind>
void set_wrap_t(GLuint texture_id, Wrap wrap)
{
    static_assert(internal::texture_dimension<Texture_Kind>() >= 2);
    internal::assert_texture_is_bound<Texture_Kind>(texture_id,
                                                    "You must bind the texture before setting its wrap mode");
    glTexParameteri(raw(Texture_Kind), GL_TEXTURE_WRAP_T, raw(wrap));
    glpp_check_errors();
}

template<TextureKind Texture_Kind>
void set_wrap_r(GLuint texture_id, Wrap wrap)
{
    static_assert(internal::texture_dimension<Texture_Kind>() >= 3);
    internal::assert_texture_is_bound<Texture_Kind>(texture_id,
                                                    "You must bind the texture before setting its wrap mode");
    glTexParameteri(raw(Texture_Kind), GL_TEXTURE_WRAP_R, raw(wrap));
    glpp_check_errors();
}

template<TextureKind Texture_Kind>
void generate_mipmap()
{
    glGenerateMipmap(raw(Texture_Kind));
    glpp_check_errors();
}

} // namespace glpp
