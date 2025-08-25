#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <vector>
#include <memory>
#include <cstddef>

template <typename T>
class Tensor {
public:
    Tensor(const std::vector<size_t>& shape);
    Tensor(const Tensor& other);
    Tensor(Tensor&& other) noexcept;
    ~Tensor();

    // Operators, e.g., element access
    T& operator()(const std::vector<size_t>& indices);
    // Add matrix ops later

private:
    std::vector<size_t> shape_;
    std::unique_ptr<T[]> data_;
    size_t size_;
};

#endif // TENSOR_HPP