#include "UniqueBuffer.h"

namespace glpp {

UniqueBuffer::UniqueBuffer()
{
    glGenBuffers(1, &_id);
}

UniqueBuffer::~UniqueBuffer()
{
    glDeleteBuffers(1, &_id);
}

UniqueBuffer::UniqueBuffer(UniqueBuffer&& rhs) noexcept
    : _id{rhs._id}
{
    rhs._id = 0;
}

UniqueBuffer& UniqueBuffer::operator=(UniqueBuffer&& rhs) noexcept
{
    if (this != &rhs) {
        _id     = rhs._id;
        rhs._id = 0;
    }
    return *this;
}

} // namespace glpp