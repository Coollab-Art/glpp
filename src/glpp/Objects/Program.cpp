#include "Program.h"
#include <glpp/internal/assert_is_bound.h>
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

GLint Program::compute_uniform_location(const char* uniform_name) const
{
    const auto location = glGetUniformLocation(*id_, uniform_name);
    glpp::check_errors();
    return location;
}

static void assert_is_used(GLuint id)
{
    internal::assert_is_bound(GL_CURRENT_PROGRAM, static_cast<GLint>(id),
                              "The program must be in use before setting any uniform");
}

void Program::set_uniform(GLint uniform_location, int v) const
{
    assert_is_used(*id_);
    glUniform1i(uniform_location, v);
    glpp::check_errors();
}
void Program::set_uniform(GLint uniform_location, unsigned int v) const
{
    set_uniform(uniform_location, static_cast<int>(v));
}
void Program::set_uniform(GLint uniform_location, bool v) const
{
    set_uniform(uniform_location, v ? 1 : 0);
}
void Program::set_uniform(GLint uniform_location, float v) const
{
    assert_is_used(*id_);
    glUniform1f(uniform_location, v);
    glpp::check_errors();
}
void Program::set_uniform(GLint uniform_location, float x, float y) const
{
    assert_is_used(*id_);
    glUniform2f(uniform_location, x, y);
    glpp::check_errors();
}
void Program::set_uniform(GLint uniform_location, float x, float y, float z) const
{
    assert_is_used(*id_);
    glUniform3f(uniform_location, x, y, z);
    glpp::check_errors();
}
void Program::set_uniform(GLint uniform_location, float x, float y, float z, float w) const
{
    assert_is_used(*id_);
    glUniform4f(uniform_location, x, y, z, w);
    glpp::check_errors();
}
void Program::set_uniform_mat2(GLint uniform_location, const float m[4]) const // NOLINT
{
    assert_is_used(*id_);
    glUniformMatrix2fv(uniform_location, 1, GL_FALSE, m);
    glpp::check_errors();
}
void Program::set_uniform_mat3(GLint uniform_location, const float m[9]) const // NOLINT
{
    assert_is_used(*id_);
    glUniformMatrix3fv(uniform_location, 1, GL_FALSE, m);
    glpp::check_errors();
}
void Program::set_uniform_mat4(GLint uniform_location, const float m[16]) const // NOLINT
{
    assert_is_used(*id_);
    glUniformMatrix4fv(uniform_location, 1, GL_FALSE, m);
    glpp::check_errors();
}

} // namespace glpp