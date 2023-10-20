#include <gtest/gtest.h>
#include "command_manager.hpp"
#include <vector>

TEST(Basic, CheckConstruct1) {
    std::vector<std::vector<bool>> v(3, std::vector<bool>(3, false));
    v[1][1] = true;
    CommandManager manager(v);
    manager.SetParams(1, {1, 1}, 1);
}

TEST(Basic, CheckGetEnv1) {
    std::vector<std::vector<bool>> v(5, std::vector<bool>(5, false));
    v[2][2] = true;
    CommandManager manager(v);
    manager.SetParams(1, {1, 1}, 1);
    decltype(v) env;
    manager.SetEnv(env);
    ASSERT_TRUE(env[1][1]);

    ASSERT_FALSE(env[0][1]);
    ASSERT_FALSE(env[1][0]);
    ASSERT_FALSE(env[2][2]);
    ASSERT_FALSE(env[2][0]);
    ASSERT_FALSE(env[2][1]);

}

