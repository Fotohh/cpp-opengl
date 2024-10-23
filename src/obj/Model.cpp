//
// Created by zinha on 10/21/2024.
//

#include "Model.h"


int model::get_vertex_count() const {
    return m_vertex_count_;
}

float* model::get_vertices() const{
    return m_vertices_;
}

int model::get_index_location() const {
    return m_index_location_;
}

void model::set_index_location(const int loc) {
    m_index_location_ = loc;
}




