// Placeholder for Google Test
#include <gtest/gtest.h>
#include "core/Tensor.hpp"

TEST(TensorTest, BasicCreation) {
    Tensor<float> t({2, 2});
    EXPECT_EQ(4, /* compute size somehow */);
}