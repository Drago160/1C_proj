#pragma once

#include <string>
#include <vector>
#include "geom_struct.hpp"

class CommandManager {
public:
    CommandManager(const std::vector<std::vector<bool>>& field) : field_(field) {}
    void SetParams(int, const Cord&, size_t);
    Cord GoThrow();
    void Rotate(bool rotate_direction); // true: clockwise
    void SetEnv(std::vector<std::vector<bool>>& loc_env);
    bool LastGoSuccess() const { return !dead_lock_flag;}
private:
    bool dead_lock_flag = true;
    int direction_;
    Cord cord_;
    size_t loc_env_size_;
    const std::vector<std::vector<bool>>& field_;
};

// геттеры параметров, чтобы только этот класс знал координаты
// посчет времени операций + стоимость от них собирать
// сделать TODO в методах
// принимать