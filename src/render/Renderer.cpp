//
// Created by zinha on 10/20/2024.
//

#include "Renderer.h"


void renderer::init() {
    const size_t model_count = m_manager_->get_model_size();

    glGenVertexArrays(model_count, m_vaos_);
    glGenBuffers(model_count, m_vbos_);

    for (size_t i = 0; i < model_count; i++) {
        const model *model = m_manager_->get_models()[i];
        glBindVertexArray(m_vaos_[i]);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbos_[i]);

        // Assuming get_vertices returns a pointer to the vertex data
        glBufferData(GL_ARRAY_BUFFER, model->get_vertex_count() * sizeof(float) * 3, model->get_vertices(),
                     GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);
    }
}

void renderer::update() const {
    glUseProgram(m_shader_.get_shader_program());
    for (size_t i = 0; i < m_manager_->get_model_size(); ++i) {
        glBindVertexArray(m_vaos_[i]);
        glDrawArrays(GL_TRIANGLES, 0, m_manager_->get_models()[i]->get_vertex_count());
    }
}

void renderer::unload() const {
    for (size_t i = 0; i < m_manager_->get_model_size(); ++i) {
        glDeleteVertexArrays(1, &m_vaos_[i]);
        glDeleteBuffers(1, &m_vbos_[i]);
        //glDeleteBuffers(1, &m_ebos_[i]);
    }
    glDeleteProgram(m_shader_.get_shader_program());
}
