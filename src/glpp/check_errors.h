#pragma once

#include <functional>
#include <string>
namespace glpp {

/// Checks if there has been errors since the last check_errors() call, and calls the callback set with set_error_callback() if there were any errors.
/// You should call this after each raw OpenGL call (the glpp calls already do that for you)
/// Note that this is not really necessary if you have enabled modern OpenGL debugging (available since OpenGL 4.3)
#define check_errors() internal::check_errors_with_infos(__FILE__, __func__, __LINE__)

/// Sets the function that is called when errors are detected by check_errors()
/// The callback will receive a string containing the error messages
/// If you do not set a callback, by default glpp will log to std::cerr
void set_error_callback(std::function<void(std::string&&)> callback);

/// Must be called just after you destroy your OpenGL context during the program's shutdown
/// This prevents glpp from freezing if you destroy glpp objects after the context has been destroyed
void shut_down();

namespace internal {
void check_errors_with_infos(const char* file_name = nullptr, const char* function_name = nullptr, const int line = -1);
} // namespace internal

} // namespace glpp