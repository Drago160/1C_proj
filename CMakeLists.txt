cmake_minimum_required(VERSION 3.6)

project(1C VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" ${CMAKE_SOURCE_DIR}/cmake)


enable_testing()

include_directories(
    include/tools
    include
    include/algorithms
)


add_executable(run 
    src/command_impl.cpp 
    src/algo.cpp
    src/greed.cpp
    main.cpp)

add_subdirectory(tests)



