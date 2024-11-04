#include "Shader.h"

#include <fstream>

bool Shader::init_vertex_shader(const char *vertex_path) {
    m_vertex_shader_ = glCreateShader(GL_VERTEX_SHADER);
    const bool vert_status = compile_shader(m_vertex_shader_, vertex_path);

    if (!vert_status) {
        std::cout << "Failed to load vertex shaders!" << std::endl;
        return false;
    }
    return true;
}



unsigned int Shader::create_shader_program(const char* path) const {

    const unsigned int shader = glCreateShader(GL_FRAGMENT_SHADER);
    const unsigned int program = glCreateProgram();

    const bool status = compile_shader(shader, path);

    if(!status) {
        std::cout << "Failed to load fragment shaders!" << std::endl;
        return 0;
    }

    int success;

    glAttachShader(program, m_vertex_shader_);
    glAttachShader(program, shader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char log[512];
        glGetProgramInfoLog(program, 512, nullptr, log);
        std::cout << "ERROR::SHADER::LINKING_FAILED\n" << log << std::endl;
        return 0;
    }
    glDeleteShader(shader);
    return program;
}
bool Shader::compile_shader(const unsigned int shader, const char *path) {
    std::ifstream file(path);
    const std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    const char *stream = str.c_str();
    file.close();
    glShaderSource(shader, 1, &stream, nullptr);
    glCompileShader(shader);
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char log[512];
        glGetShaderInfoLog(shader, 512, nullptr, log);
        std::cout << "ERROR:SHADER::COMPILATION_FAILED\n" << log << std::endl;
        return nullptr;
    }
    return stream;
}

void Shader::cleanup() const {
    glDeleteShader(m_vertex_shader_);
}