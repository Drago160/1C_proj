#include "greed.hpp"

bool GreedDFSSolver::ExistsRoad(const Cord& cord) {
    auto it = map_info_.find(cord);
    if (it == map_info_.end()) {
        return false;
    }
    return it->second == CordInfoType::Road;
}

// если вокруг хоть 1 клетка стена - разводим костер
void GreedDFSSolver::CheckLocal(const Cord& cord) {
    for (const auto& pair : possible_deltas_) {
        Cord bias_cord = {cord.x + pair.first, cord.y + pair.second};
        if (!map_info_.contains(bias_cord) || map_info_[bias_cord] != CordInfoType::UnCategorized) {
            GetLocalEnv(cord);
            break;
        }
    }
}

// получаем и парсим локальную карту от manager
void GreedDFSSolver::GetLocalEnv(const Cord& cord) {
    std::vector<std::vector<bool>> manager_env;
    comand_manager_.SetEnv(manager_env);

    // костыль из-за недоделанного метода в CommandManager
    for (size_t x = 0; x < 2 * loc_env_size_ + 1; ++x) {
        for (size_t y = 0; y < 2 * loc_env_size_ + 1; ++y) {
            if (manager_env[x][y]) {
                map_info_[{x + cord_.x, y + cord_.y}] = CordInfoType::Road;
            } else {
                if (x == loc_env_size_ || y == loc_env_size_) {
                    map_info_[{x + cord_.x, y + cord_.y}] = CordInfoType::Wall;
                    continue;
                }
                map_info_[{x + cord_.x, y + cord_.y}] = CordInfoType::UnCategorized;
            }
        }
    }
}

void GreedDFSSolver::DFS() {
    CheckLocal(cord_);

    // считаем относительно нашего направления
    auto delta = possible_deltas_[(direction_ + 1) % 4]; 
    Cord bias_cord = {cord_.x + delta.first, cord_.y + delta.second};

    if (map_info_[bias_cord] == CordInfoType::Road && !used_.contains(bias_cord)) {
        direction_ = (direction_ + 1) % 4;
        comand_manager_.Rotate(true);
        cord_ = comand_manager_.GoThrow();
        int curr_dir = direction_;
        Cord curr_cord = cord_;
        DFS();
        // возвращаемся назад
        comand_manager_.Rotate(true);
        comand_manager_.Rotate(true);
        while (curr_cord != cord_) {
            cord_ = comand_manager_.GoThrow();
        }
        //  разворачиваемся к исходному положению
        comand_manager_.Rotate(true);
        comand_manager_.Rotate(true);
    }

    delta = possible_deltas_[(direction_ + 3) % 4];
    bias_cord = {cord_.x + delta.first, cord_.y + delta.second};

    if (map_info_[bias_cord] == CordInfoType::Road && !used_.contains(bias_cord)) {
        direction_ = (direction_ + 1) % 4;
        comand_manager_.Rotate(false);
        cord_ = comand_manager_.GoThrow();
        Cord curr_cord = cord_;
        int curr_dir = direction_;
        DFS();
        // возвращаемся назад
        comand_manager_.Rotate(true);
        comand_manager_.Rotate(true);
        while (curr_cord != cord_) {
            cord_ = comand_manager_.GoThrow();
        }
        comand_manager_.Rotate(true);
        comand_manager_.Rotate(true);
        // разворот в исходную позицию
    }

    //TODO:
    // избавиться от копипасты
    // не делать двойных разворотов а помнить какой сделан
}



void GreedDFSSolver::TrySolve() {
    map_info_[{0, 0}] = CordInfoType::Road;
    used_.insert({0, 0});
    DFS();
    // из последнего DFS возвращаться не требуется 
}