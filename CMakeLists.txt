cmake_minimum_required(VERSION 3.8)

set(WARNINGS_AS_ERRORS_FOR_GLPP OFF CACHE BOOL "ON iff you want to treat warnings as errors")

add_library(glpp)
add_library(glpp::glpp ALIAS glpp)
target_compile_features(glpp PUBLIC cxx_std_17)

# Set warning level
if(MSVC)
    target_compile_options(glpp PRIVATE /W4)
else()
    target_compile_options(glpp PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion)
endif()

# Maybe enable warnings as errors
if(WARNINGS_AS_ERRORS_FOR_GLPP)
    if(MSVC)
        target_compile_options(glpp PRIVATE /WX)
    else()
        target_compile_options(glpp PRIVATE -Werror)
    endif()
endif()

# ---Add glad---
add_library(glad third-party/glad/src/gl.c)
target_include_directories(glad PUBLIC third-party/glad/include)
target_link_libraries(glpp PUBLIC glad)
install(FILES "third-party/glad/include/KHR/khrplatform.h" DESTINATION "license/KHR")

# ---Add source files---
if(WARNINGS_AS_ERRORS_FOR_GLPP)
    target_include_directories(glpp INTERFACE include)
    target_include_directories(glpp PUBLIC src)
else()
    target_include_directories(glpp SYSTEM INTERFACE include)
    target_include_directories(glpp SYSTEM PUBLIC src)
endif()

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)
target_sources(glpp PRIVATE ${SRC_FILES})