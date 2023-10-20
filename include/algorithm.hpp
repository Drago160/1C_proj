#pragma once
#include <vector>

#include "command_manager.hpp"
#include "geom_struct.hpp"

class TaskSolver {
    TaskSolver(CommandManager& ComandManager) : comand_manager_(ComandManager) {}
    void SetParams(int direction, const Cord& cord, size_t loc_env_size);
    virtual void TrySolve() = 0;
protected:
    Cord cord_;
    size_t loc_env_size_;
    int direction_;
    CommandManager& comand_manager_;
};
// TODO:
// не хранить координату и direction, а получать из command_manager