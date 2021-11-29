cmake_minimum_required(VERSION 3.8)

add_library(glpp)
add_library(glpp::glpp ALIAS glpp)
target_compile_features(glpp PRIVATE cxx_std_11)

if (MSVC)
    target_compile_options(glpp PRIVATE /WX /W4)
else()
    target_compile_options(glpp PRIVATE -Werror -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion)
endif()

# ---Add glad---
add_library(glad third-party/glad/src/glad.c)
target_include_directories(glad PUBLIC third-party/glad/include)
target_link_libraries(glpp PUBLIC glad)

# ---Add source files---
target_include_directories(glpp INTERFACE include)
target_include_directories(glpp PUBLIC src)
target_sources(glpp PRIVATE
    src/glpp/check_errors.cpp
    src/glpp/Functions/Texture.cpp
    src/glpp/Functions/Program.cpp
    src/glpp/Functions/Framebuffer.cpp
    src/glpp/Functions/Miscellaneous.cpp
    src/glpp/internal/assert_is_bound.cpp
)