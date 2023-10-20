#include <iostream>

#include "command_manager.hpp"

int main(int argc, char **argv) {
  auto v = std::vector<std::vector<bool>>(3, std::vector<bool>(3, false));
  v[1][1] = true;
  CommandManager manager(v);
}

// TODO общее:
// консольный интерфейс, чтобы самому ходить по лабиринту
// Добавить тесты к алгоритму
// избавиться от копипасты
// 