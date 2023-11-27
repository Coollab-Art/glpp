#include "VertexArray.h"
#include <glpp/check_errors.h>
#include <glpp/internal/assert_is_bound.h>
#include <stdexcept>

namespace glpp {

void bind_vertex_array(UniqueVertexArray const& vao)
{
    bind_vertex_array(vao.id());
}

void bind_vertex_array(GLuint vao_id)
{
    glBindVertexArray(vao_id);
    glpp_check_errors();
}

GLenum raw(PrimitiveDrawMode mode)
{
    switch (mode)
    {
    case PrimitiveDrawMode::Points:
        return GL_POINTS;
    case PrimitiveDrawMode::LineStrip:
        return GL_LINE_STRIP;
    case PrimitiveDrawMode::LineLoop:
        return GL_LINE_LOOP;
    case PrimitiveDrawMode::Lines:
        return GL_LINES;
    case PrimitiveDrawMode::TriangleStrip:
        return GL_TRIANGLE_STRIP;
    case PrimitiveDrawMode::TriangleFan:
        return GL_TRIANGLE_FAN;
    case PrimitiveDrawMode::Triangles:
        return GL_TRIANGLES;
    case PrimitiveDrawMode::LinesAdjacency:
        return GL_LINES_ADJACENCY;
    case PrimitiveDrawMode::LineStripAdjacency:
        return GL_LINE_STRIP_ADJACENCY;
    case PrimitiveDrawMode::TrianglesAdjacency:
        return GL_TRIANGLES_ADJACENCY;
    case PrimitiveDrawMode::TriangleStripAdjacency:
        return GL_TRIANGLE_STRIP_ADJACENCY;
    case PrimitiveDrawMode::Patches:
        return GL_PATCHES;
    }
    throw std::logic_error{"Missing case in enum! This is a bug in glpp, this should never happen"};
}

void draw_arrays_instanced(UniqueVertexArray const& vao, PrimitiveDrawMode mode, GLint first, GLsizei count, GLsizei instance_count)
{
    return draw_arrays_instanced(vao.id(), mode, first, count, instance_count);
}

void draw_arrays_instanced(GLuint vao_id, PrimitiveDrawMode mode, GLint first, GLsizei count, GLsizei instance_count)
{
    internal::assert_is_bound(
        GL_VERTEX_ARRAY_BINDING, static_cast<GLint>(vao_id),
        "You must bind the vao before drawing with it."
    );
    glDrawArraysInstanced(raw(mode), first, count, instance_count);
    glpp_check_errors();
}

} // namespace glpp