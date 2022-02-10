#pragma once

#include <glad/glad.h>

namespace glpp {

/// Corresponds to the `type` of a texture as described [here](https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glTexImage2D.xhtml)
enum class TexelDataType : GLenum {
    UnsignedByte               = GL_UNSIGNED_BYTE,
    Byte                       = GL_BYTE,
    UnsignedShort              = GL_UNSIGNED_SHORT,
    Short                      = GL_SHORT,
    UnsignedInt                = GL_UNSIGNED_INT,
    Int                        = GL_INT,
    Float                      = GL_FLOAT,
    UnsignedByte_3_3_2         = GL_UNSIGNED_BYTE_3_3_2,
    UnsignedByte_2_3_3_Rev     = GL_UNSIGNED_BYTE_2_3_3_REV,
    UnsignedShort_5_6_5        = GL_UNSIGNED_SHORT_5_6_5,
    UnsignedShort_5_6_5_Rev    = GL_UNSIGNED_SHORT_5_6_5_REV,
    UnsignedShort_4_4_4_4      = GL_UNSIGNED_SHORT_4_4_4_4,
    UnsignedShort_4_4_4_4_Rev  = GL_UNSIGNED_SHORT_4_4_4_4_REV,
    UnsignedShort_5_5_5_1      = GL_UNSIGNED_SHORT_5_5_5_1,
    UnsignedShort_1_5_5_5_Rev  = GL_UNSIGNED_SHORT_1_5_5_5_REV,
    UnsignedInt_8_8_8_8        = GL_UNSIGNED_INT_8_8_8_8,
    UnsignedInt_8_8_8_8_Rev    = GL_UNSIGNED_INT_8_8_8_8_REV,
    UnsignedInt_10_10_10_2     = GL_UNSIGNED_INT_10_10_10_2,
    UnsignedInt_2_10_10_10_Rev = GL_UNSIGNED_INT_2_10_10_10_REV,
};

} // namespace glpp
