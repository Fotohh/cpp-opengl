
#ifndef SHADER_H
#define SHADER_H
#include <glad/glad.h>

class shader {

public:
    shader(char* vertex_path, char* fragment_path) : m_vertex_path_(vertex_path), m_fragment_path_(fragment_path) {
        m_vertex_shader_ = glCreateShader(GL_VERTEX_SHADER);
        m_fragment_shader_ = glCreateShader(GL_FRAGMENT_SHADER);
    }

    bool init();
    unsigned int get_vertex_shader() const;
    unsigned int get_fragment_shader() const;
    unsigned int get_shader_program() const;

private:
    bool compile_shader(GLuint type) const;

private:
    unsigned int m_vertex_shader_;
    unsigned int m_fragment_shader_;
    unsigned int m_shader_program_{};
    char* m_vertex_path_;
    char* m_fragment_path_;
};


#endif //SHADER_H
