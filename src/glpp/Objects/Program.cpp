#include "Program.h"
#include <glpp/internal/get_info_log.h>

namespace glpp {

void Program::attach_shader(GLuint shader_id) const
{
    glAttachShader(*id_, shader_id);
    glpp::check_errors();
}

void Program::link() const
{
    glLinkProgram(*id_);
    glpp::check_errors();
}

static void get_validation(GLuint id, GLint* result)
{
    glGetProgramiv(id, GL_VALIDATE_STATUS, result);
}
static void get_log_length(GLuint id, GLsizei* result)
{
    glGetProgramiv(id, GL_INFO_LOG_LENGTH, result);
}
static void get_log(GLuint id, GLsizei length, GLchar* message)
{
    glGetProgramInfoLog(id, length, nullptr, message);
}

MaybeError Program::check_linking_errors() const
{
    glValidateProgram(*id_);
    glpp::check_errors();
    return internal::get_info_log<&get_validation,
                                  &get_log_length,
                                  &get_log>(*id_);
}

void Program::use() const
{
    glUseProgram(*id_);
    glpp::check_errors();
}

GLint Program::uniform_location(const char* uniform_name) const
{
    const auto location = glGetUniformLocation(*id_, uniform_name);
    glpp::check_errors();
    return location;
}

} // namespace glpp