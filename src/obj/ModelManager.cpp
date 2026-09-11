//
// Created by zinha on 10/23/2024.
//

#include "ModelManager.h"

#include <algorithm>

void ModelManager::add_model(const Model model) {
    m_models_.push_back(model);
}

const std::vector<Model> &ModelManager::get_models() const {
    return m_models_;
}

size_t ModelManager::size() const {
    return m_models_.size();
}

void ModelManager::remove_model(const Model model) {
    auto it = std::find(m_models_.begin(), m_models_.end(), model);
    if(it == m_models_.end()) return;

    std::vector<Model> models;
    models.reserve(m_models_.size() - 1);

    for(auto model_it = m_models_.begin(); model_it != m_models_.end(); model_it++) {
        if(model_it != it) models.push_back(*model_it);
    }

    m_models_.swap(models);
}
