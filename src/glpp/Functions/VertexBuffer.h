#pragma once
#include <glpp/UniqueHandles/UniqueBuffer.h>
#include <span>

namespace glpp {

enum class DataAccessFrequency {
    Stream,  // The data will be modified once and used at most a few times.
    Static,  // The data will be modified once and used many times.
    Dynamic, // The data will be modified repeatedly and used many times.
};

void bind_vertex_buffer(UniqueBuffer const& vertex_buffer);
void bind_vertex_buffer(GLuint vertex_buffer_id);

void set_vertex_buffer_data(UniqueBuffer const& vertex_buffer, DataAccessFrequency, std::span<float const> data);
void set_vertex_buffer_data(GLuint vertex_buffer_id, DataAccessFrequency, std::span<float const> data);

void set_vertex_buffer_attribute(UniqueBuffer const& vertex_buffer, GLuint attribute_index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, void const* pointer);
void set_vertex_buffer_attribute(GLuint vertex_buffer_id, GLuint attribute_index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, void const* pointer);

} // namespace glpp