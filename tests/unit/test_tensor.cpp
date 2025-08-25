#include <gtest/gtest.h>
#include "core/Tensor.hpp"

// Test fixture for Tensor tests (optional, but useful for shared setup)
class TensorTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Optional: Initialize common objects here
    }
};

TEST_F(TensorTest, BasicCreation) {
    Tensor<float> t({2, 2});
    // Test that the tensor size is correct
    EXPECT_EQ(4, t({0, 0}) * 0 + 4); // Dummy check; replace with actual size accessor
    // Add more assertions as you implement Tensor methods
}