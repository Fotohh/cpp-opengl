#include "ModelManager.h"

void model_manager::add_model(model& model) {
    m_models_.push_back(&model);
}

void model_manager::remove_model(const int pos) {
    if (pos >= 0 && pos < m_models_.size()) {
        m_models_.erase(m_models_.begin() + pos);
    }
}

std::vector<model*> model_manager::get_models() {
    return m_models_;
}

size_t model_manager::get_model_size() const {
    return m_models_.size();
}
