#include "geom_struct.hpp"
#include <cstddef>
#include <functional>

enum class CordInfoType { Wall, Road, UnCategorized };

struct PairHash {
    auto operator()(const Cord& cord) const -> size_t {
        return std::hash<size_t>{}(cord.x) ^ std::hash<size_t>{}(cord.y);
    }
};