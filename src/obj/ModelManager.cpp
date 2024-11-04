//
// Created by zinha on 10/23/2024.
//

#include "ModelManager.h"

void ModelManager::add_model(const Model model) {
    m_models_.push_back(model);
}

const std::vector<Model> &ModelManager::get_models() const {
    return m_models_;
}

size_t ModelManager::size() const {
    return m_models_.size();
}

void ModelManager::remove_model(const Model model) const {
    auto it = std::find(m_models_.begin(), m_models_.end(), model);
}
