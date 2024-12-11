cmake_minimum_required(VERSION 3.20)

set(WARNINGS_AS_ERRORS_FOR_GLPP OFF CACHE BOOL "ON iff you want to treat warnings as errors")

add_library(glpp)
add_library(glpp::glpp ALIAS glpp)
target_compile_features(glpp PUBLIC cxx_std_20)

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
target_include_directories(glad SYSTEM PUBLIC third-party/glad/include)
target_link_libraries(glpp PUBLIC glad)
install(FILES "third-party/glad/include/KHR/khrplatform.h" DESTINATION "license/KHR")

# ---Add source files---
if(WARNINGS_AS_ERRORS_FOR_GLPP)
    set(MAYBE_SYSTEM "")
else()
    set(MAYBE_SYSTEM "SYSTEM")
endif()

target_include_directories(glpp ${MAYBE_SYSTEM} INTERFACE include)
target_include_directories(glpp ${MAYBE_SYSTEM} PUBLIC src)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)
target_sources(glpp PRIVATE ${SRC_FILES})