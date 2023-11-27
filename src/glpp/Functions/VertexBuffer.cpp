#include "VertexBuffer.h"
#include <stdexcept>
#include "../internal/assert_is_bound.h"

namespace glpp {

void bind_vertex_buffer(UniqueBuffer const& vertex_buffer)
{
    bind_vertex_buffer(vertex_buffer.id());
}
void bind_vertex_buffer(GLuint vertex_buffer_id)
{
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);
    glpp_check_errors();
}

static auto raw(DataAccessFrequency access_frequency) -> GLenum
{
    switch (access_frequency)
    {
    case glpp::DataAccessFrequency::Stream:
    {
        return GL_STREAM_DRAW;
    }
    case glpp::DataAccessFrequency::Static:
    {
        return GL_STATIC_DRAW;
    }
    case glpp::DataAccessFrequency::Dynamic:
    {
        return GL_DYNAMIC_DRAW;
    }
    }
    throw std::logic_error{"Missing case in enum! This is a bug in glpp, this should never happen"};
}

void set_vertex_buffer_data(UniqueBuffer const& vertex_buffer, DataAccessFrequency access_frequency, std::span<float const> data)
{
    set_vertex_buffer_data(vertex_buffer.id(), access_frequency, data);
}

void set_vertex_buffer_data(GLuint vertex_buffer_id, DataAccessFrequency access_frequency, std::span<float const> data)
{
    internal::assert_is_bound(
        GL_ARRAY_BUFFER_BINDING, static_cast<GLint>(vertex_buffer_id),
        "You must bind the buffer before setting its data."
    );
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), raw(access_frequency));
    glpp_check_errors();
}

void set_vertex_buffer_attribute(UniqueBuffer const& vertex_buffer, GLuint attribute_index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, void const* pointer)
{
    set_vertex_buffer_attribute(vertex_buffer.id(), attribute_index, size, type, normalized, stride, pointer);
}

void set_vertex_buffer_attribute(GLuint vertex_buffer_id, GLuint attribute_index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, void const* pointer)
{
    internal::assert_is_bound(
        GL_ARRAY_BUFFER_BINDING, static_cast<GLint>(vertex_buffer_id),
        "You must bind the buffer before setting its vertex attributes."
    );
    glEnableVertexAttribArray(attribute_index);
    glpp_check_errors();
    glVertexAttribPointer(attribute_index, size, type, normalized, stride, pointer);
    glpp_check_errors();
}

} // namespace glpp