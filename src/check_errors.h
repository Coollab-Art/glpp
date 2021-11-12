#pragma once

namespace glpp {

/// If you build in Debug mode: Checks if there has been errors since the last check_errors() call
/// If you build in Release mode: Does nothing (you can use check_errors_even_in_release() if you want)
/// You should call this after each raw OpenGL call (the glpp calls already do that for you)
/// Note that this is not really necessary if you have enabled modern OpenGL debugging (available since OpenGL 4.3)
void check_errors();

/// Same as check_errors() but is not removed when you build in Release mode
void check_errors_even_in_release();

} // namespace glpp