#include <iostream>
#include "core/Tensor.hpp"

int main() {
    std::vector<size_t> shape = {2, 3};
    Tensor<float> t(shape);
    t({0, 0}) = 1.0f;
    std::cout << "Tensor created: " << t({0, 0}) << std::endl;
    return 0;
}