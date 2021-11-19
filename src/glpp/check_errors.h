#pragma once

#include <functional>
#include <string>

namespace glpp {

/// If you build in Debug mode: Checks if there has been errors since the last check_errors() call
/// If you build in Release mode: Does nothing (you can use check_errors_even_in_release() if you want)
/// You should call this after each raw OpenGL call (the glpp calls already do that for you)
/// Note that this is not really necessary if you have enabled modern OpenGL debugging (available since OpenGL 4.3)
void check_errors();

/// Same as check_errors() but is not removed when you build in Release mode
void check_errors_even_in_release();

/// Sets the function that is called when errors are detected by check_errors() or check_errors_even_in_release()
/// The callback will receive a string containing the error message
/// If you do not set a callback, by default glpp logs to std::cerr
void set_error_callback(std::function<void(std::string&&)> callback);

/// Must be called just after you destroy your OpenGL context during the program's shutdown
/// This prevents glpp from freezing if you destroy glpp objects after the context has been destroyed
void shut_down();

} // namespace glpp