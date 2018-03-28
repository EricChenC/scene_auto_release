#pragma once

#include "game_object.h"

#include <memory>
#include <iostream>
#include <vector>

class Scene {
public:
    explicit Scene() {
        std::cout << "Scene construct\n";
    }

    ~Scene() {
        std::cout << "Scene destruct\n";
    }

    void add_root(std::shared_ptr<GameObject> game_object) {
        roots_.push_back(game_object);
    }

    std::vector<std::shared_ptr<GameObject>> get_roots() {
        return roots_;
    }

private:
    std::vector<std::shared_ptr<GameObject>>        roots_;

};