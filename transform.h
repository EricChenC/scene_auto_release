#pragma once

#include <memory>
#include <iostream>

class Transform {
public:
    explicit Transform() {
        std::cout << "Transform construct\n";
    }

    ~Transform() {
        std::cout << "Transform destruct\n";
    }

};