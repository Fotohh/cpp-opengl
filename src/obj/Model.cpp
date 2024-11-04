//
// Created by zinha on 10/21/2024.
//

#include "Model.h"


int Model::get_vertex_count() const {
    return m_vertex_count_;
}

const std::vector<float>& Model::get_vertices() {
    return m_vertices_;
}

int Model::get_index_location() const {
    return m_index_location_;
}

void Model::set_index_location(const int loc) {
    m_index_location_ = loc;
}
