#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <vector>
#include <glad/glad.h>

class Shader {
public:
    Shader() = default;

    bool init_vertex_shader(const char *vertex_path);

    unsigned int create_shader_program(const char* path) const;

    void cleanup() const;

private:
    static bool compile_shader(unsigned int, const char *path);

private:
    unsigned int m_vertex_shader_;
};


#endif //SHADER_H
