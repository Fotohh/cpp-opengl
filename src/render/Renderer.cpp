//
// Created by zinha on 10/20/2024.
//

#include "Renderer.h"


void renderer::init() {
    const size_t model_count = m_manager_->get_model_size();
    glGenVertexArrays(model_count, m_vaos_);
    glGenBuffers(model_count, m_vbos_);
}

void renderer::add_model(model &model) {
    glBindVertexArray(m_vaos_[m_init_count_]);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbos_[m_init_count_]);

    glBufferData(GL_ARRAY_BUFFER, model.get_vertex_count() * sizeof(float) * 3, model.get_vertices(),
                     GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);
    m_init_count_++;
    m_manager_->add_model(model);
}


void renderer::render_model(const model &model) {
    glBindVertexArray(m_vaos_[m_render_count_]);
    glDrawArrays(GL_TRIANGLES, 0, model.get_vertex_count());
    m_render_count_++;
}

void renderer::unload() const {
    const size_t model_count = m_manager_->get_model_size();
    glDeleteVertexArrays(model_count, m_vaos_);
    glDeleteBuffers(model_count, m_vbos_);
}
