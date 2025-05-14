#pragma once
#include <glpp/UniqueHandles/UniqueVertexArray.h>

namespace glpp {

void bind_vertex_array(UniqueVertexArray const& vao);
void bind_vertex_array(GLuint vao_id);

enum class PrimitiveDrawMode {
    Points,
    LineStrip,
    LineLoop,
    Lines,
    TriangleStrip,
    TriangleFan,
    Triangles,
    LinesAdjacency,
    LineStripAdjacency,
    TrianglesAdjacency,
    TriangleStripAdjacency,
    Patches,
};
GLenum raw(PrimitiveDrawMode);

void draw_arrays(UniqueVertexArray const& vao, PrimitiveDrawMode mode, GLint first, GLsizei count);
void draw_arrays(GLuint vao_id, PrimitiveDrawMode mode, GLint first, GLsizei count);

void draw_arrays_instanced(UniqueVertexArray const& vao, PrimitiveDrawMode mode, GLint first, GLsizei count, GLsizei instance_count);
void draw_arrays_instanced(GLuint vao_id, PrimitiveDrawMode mode, GLint first, GLsizei count, GLsizei instance_count);

} // namespace glpp