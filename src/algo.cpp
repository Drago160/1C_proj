#include "algorithm.hpp"

void TaskSolver::SetParams(int direction, const Cord& cord, size_t loc_env_size) {
    loc_env_size_ = loc_env_size;
    direction_ = direction;
    cord_ = cord;
}