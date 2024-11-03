//
// Created by zinha on 10/23/2024.
//

#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <vector>

#include "Model.h"


class model_manager {
public:
    model_manager() = default;

    void add_model(model model);

    void remove_model(model model) const;

    const std::vector<model> &get_models() const;

    size_t size() const;

private:
    std::vector<model> m_models_;
};


#endif //MODELMANAGER_H
