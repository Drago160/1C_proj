cmake_minimum_required(VERSION 3.6)
project(gtest)

enable_testing()

include_directories(
     ${CMAKE_SOURCE_DIR}/include
)

add_executable(tests test.cpp ${CMAKE_SOURCE_DIR}/src/impl.cpp)

target_link_libraries(tests gtest gtest_main)

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)
