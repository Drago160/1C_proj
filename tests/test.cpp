#include <gtest/gtest.h>
#include <f.hpp>

TEST(test1, test1) {
    ASSERT_EQ(f(1, 1), 2);
}

TEST(test2, test2) {
    ASSERT_EQ(f(2, 8), 10);
}

