cmake_minimum_required(VERSION 3.6)
project(gtest)

enable_testing()

include_directories(
     ${CMAKE_SOURCE_DIR}/include
     ${CMAKE_SOURCE_DIR}/include/tools
     ${CMAKE_SOURCE_DIR}/include/algorithms
)

add_executable(tests 
     test.cpp 
     ${CMAKE_SOURCE_DIR}/src/command_impl.cpp
     ${CMAKE_SOURCE_DIR}/src/greed.cpp
     ${CMAKE_SOURCE_DIR}/src/algo.cpp
     )


target_link_libraries(tests gtest gtest_main)

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)
