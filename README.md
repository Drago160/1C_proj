#### ФИО:
Мешков Владислав Сергеевич
#### Номер задания:

#### Прочее:
Группа: Б05-151б, Физтех-школа: ФПМИ

#### Идейно:
Есть менеджер, реализующий итерактивно взаимодействие, относительно которого делаются алгоритмы.
Для алгоритмов можно придумать абстрактный класс, чтобы реализовать несколько и использовать с удобным API.
Реализовать DFS - наследник базового класса, который проходит по лабиринту, использую соотв. алгоритм

#### Структурно:
- CommandManager - реализует итерактивное взаимодействие с алгоритмами, также считет время
- TaskSolver - реализует интерфейс для классов, решающих данную задачу
- GreedDFSSolver - реализует класс DFS поиска
- tools - тут вспомогательные классы и структуры


##### Чтобы собрать проект досточно:
```
mkdir build
cmake ..
make
```

Если надо запустить тесты, запустите из корня
```
./tests/bin/tests
```