#pragma once

#include <string>
#include "ShaderKind.h"

namespace glpp {

struct ShaderDescription {
    std::string source_code;
    ShaderKind  kind;
    std::string name;
};

} // namespace glpp