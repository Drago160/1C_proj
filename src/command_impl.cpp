#include "command_manager.hpp"

void CommandManager::SetParams(int direction, const Cord& cord, size_t loc_env_size) {
    loc_env_size_ = loc_env_size;
    direction_ = direction;
    cord_ = cord;
}

Cord CommandManager::GoThrow() {
    int dx = 0;
    int dy = 0;
    if (direction_ == 0) { // up
        dy = 1;
    } else if (direction_ == 1) { // left
        dx = -1;    
        if (cord_.x == 0) {
            dead_lock_flag = false;
            return {cord_};
        }
    } else if (direction_ == 2) { // down
        dy = -1;        
        if (cord_.y == 0) {
            dead_lock_flag = true;
            return {cord_};
        }
    } else if (direction_ == 3) { // right
        dx = 1;
    }
    if (field_[cord_.x + dx][cord_.y + dy]) {
        cord_.x += dx;
        cord_.y += dy;
    }
    dead_lock_flag = true;
    return cord_;
}

void CommandManager::Rotate(bool rotate_direction) {
    if (rotate_direction) {
        ++direction_;
        return;
    }
    --direction_;
    if (direction_ == -1) {
        direction_ = 3;
    }
}

void CommandManager::SetEnv(std::vector<std::vector<bool>>& loc_env) {
    loc_env.resize((2*loc_env_size_ + 1), std::vector<bool>(2*loc_env_size_ + 1, false));
    Cord center = {loc_env_size_, loc_env_size_};
    size_t dx = 0;
    size_t dy = 0;
    loc_env[cord_.x][cord_.y] = true;
    for (dx = 0; field_[dx + cord_.x][cord_.y] && dx <= loc_env_size_; ++dx) {
        loc_env[center.x + dx][center.y] = true;
    }
    for (dx = 0; field_[cord_.x - dx][cord_.y] && dx <= loc_env_size_; ++dx) {
        loc_env[center.x + dx][center.y] = true;
    }
    for (dy = 0; field_[cord_.x][cord_.y + dy] && dy <= loc_env_size_; ++dy) {
        loc_env[center.x][center.y + dy] = true;
    }
    for (; field_[cord_.x][cord_.y - dy] && dy <= loc_env_size_; ++dy) {
        loc_env[center.x][center.y + dy] = true;
    }

    //TODO: Реализовать алгоритм лучший, чем посмотреть по сторонам и их соседям
    // можно: k^2 раз найти ответ может ли центр увидеть клетку
}
