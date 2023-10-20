#pragma once
#include <utility>
#include <cstddef>

struct Cord {
    size_t x = 0;
    size_t y = 0;
    bool operator==(const Cord& other) const {return x==other.x && y == other.y;}
};