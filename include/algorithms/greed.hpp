#include "algorithm.hpp"
#include "geom_struct.hpp"
#include "support.hpp"

#include <unordered_set>
#include <unordered_map>


class GreedDFSSolver : TaskSolver {
    void TrySolve();
    void DFS();
    bool ExistsRoad(const Cord&);
    void GetLocalEnv(const Cord&);
    void CheckLocal(const Cord&);

private:
    Cord cord_;
    const std::vector<std::pair<int, int>> possible_deltas_ = {{0, 1}, {-1, 0}, {0, 1}, {1, 0}};
    std::unordered_set<Cord, PairHash> used_;
    std::unordered_map<Cord, CordInfoType, PairHash> map_info_;
};
/*
Как работает:
Если знает хоть 1 клетку вокруг себя, идет по ней
иначе: зажигает костер и если сейчас понимае, что тупик, заканчиваем
данную ветку алгоритма и возвращаемся к последней развилке
*/


// TODO:
// мб. сделать еще BFS
// мб. реализвать алгоритмы на графах с предподсчетом заранее
// мб. сделать предподсчет графа + Дейкстру

// мб. жадный алгоритм, который идет к ближайшему непосещенному свободному пути

