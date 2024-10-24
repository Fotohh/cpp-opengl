//
// Created by zinha on 10/23/2024.
//

#include "ModelManager.h"

long model_manager::add_model(model &model) {
    m_models_.push_back(&model);
    return m_models_.size();
}

std::vector<model *> model_manager::get_models() const {
    return m_models_;
}

long model_manager::size() const {
    return m_models_.size();
}


void model_manager::remove_model(const model &model) {
    auto it = std::find(m_models_.begin(), m_models_.end(), &model);
}



