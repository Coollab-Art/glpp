#pragma once

#include <glad/gl.h>

namespace glpp {
namespace internal {

template<GLuint (*Constructor)(), void (*Destructor)(GLuint&)>
class UniqueHandle {
public:
    UniqueHandle()
        : _id{Constructor()}
    {
    }
    ~UniqueHandle()
    {
        Destructor(_id);
    }
    UniqueHandle(const UniqueHandle&)            = delete;
    UniqueHandle& operator=(const UniqueHandle&) = delete;
    UniqueHandle(UniqueHandle&& rhs) noexcept
        : _id{rhs._id}
    {
        rhs._id = 0;
    }
    UniqueHandle& operator=(UniqueHandle&& rhs) noexcept
    {
        if (this != &rhs)
        {
            Destructor(_id);
            _id     = rhs._id;
            rhs._id = 0;
        }
        return *this;
    }

    GLuint id() const { return _id; }

private:
    GLuint _id;
};

}
} // namespace glpp::internal