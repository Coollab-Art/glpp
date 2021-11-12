cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

add_library(glpp)
target_include_directories(glpp INTERFACE include)

if(MSVC)
    target_compile_options(glpp PRIVATE /WX /W4)
else()
    target_compile_options(glpp PRIVATE -Werror -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion)
endif()

# ---Add OpenGL---
find_package(OpenGL REQUIRED)
target_include_directories(glpp PUBLIC ${OPENGL_INCLUDE_DIR})
# ---Add glad---
# They don't provide CMake support so we build the glad target ourselves
add_library(glad STATIC third-party/glad/src/glad.c)
target_include_directories(glad PUBLIC third-party/glad/include)
target_link_libraries(glpp PUBLIC glad)


# ---Add glpp sources---
target_sources(glpp PRIVATE
    src/check_errors.cpp
    src/UniqueVAO.cpp
    src/UniqueBuffer.cpp
    src/UniqueShader.cpp
    src/UniqueShaderModule.cpp
    src/ShaderModule.cpp
)