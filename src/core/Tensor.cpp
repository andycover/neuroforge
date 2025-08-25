#include "core/Tensor.hpp"
#include <numeric>
#include <stdexcept>

template <typename T>
Tensor<T>::Tensor(const std::vector<size_t>& shape) : shape_(shape) {
    size_ = std::accumulate(shape.begin(), shape.end(), 1, std::multiplies<size_t>());
    data_ = std::make_unique<T[]>(size_);
}

template <typename T>
Tensor<T>::Tensor(const Tensor& other) : shape_(other.shape_), size_(other.size_) {
    data_ = std::make_unique<T[]>(size_);
    std::copy(other.data_.get(), other.data_.get() + size_, data_.get());
}

template <typename T>
Tensor<T>::Tensor(Tensor&& other) noexcept : shape_(std::move(other.shape_)), size_(other.size_), data_(std::move(other.data_)) {
    other.size_ = 0;
}

template <typename T>
Tensor<T>::~Tensor() = default;

template <typename T>
T& Tensor<T>::operator()(const std::vector<size_t>& indices) {
    if (indices.size() != shape_.size()) throw std::invalid_argument("Index mismatch");
    size_t idx = 0;
    for (size_t i = 0; i < indices.size(); ++i) {
        idx = idx * shape_[i] + indices[i];
    }
    return data_[idx];
}

// Explicit instantiations (for common types)
template class Tensor<float>;
template class Tensor<double>;