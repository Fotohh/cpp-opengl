//
// Created by zinha on 10/23/2024.
//

#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <vector>

#include "Model.h"


class ModelManager {
public:
    ModelManager() = default;

    void add_model(Model model);

    void remove_model(Model model) const;

    const std::vector<Model> &get_models() const;

    size_t size() const;

private:
    std::vector<Model> m_models_;
};


#endif //MODELMANAGER_H
