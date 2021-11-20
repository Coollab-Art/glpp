#pragma once

#include <string>

namespace glpp {

class MaybeError {
public:
    MaybeError() = default;
    explicit MaybeError(const std::string& message)
        : _has_value{true}, _message{message}
    {
    }
    const std::string& message() const { return _message; }
    bool               has_value() const { return _has_value; }
                       operator bool() const { return _has_value; }

private:
    bool        _has_value = false;
    std::string _message   = "";
};

} // namespace glpp
