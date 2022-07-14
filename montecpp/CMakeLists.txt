cmake_minimum_required(VERSION 3.0.0)
project(montecpp VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(montecpp src/main.cpp src/montecarlo.cpp src/tableVisualizer.cpp src/HTMLStubs.cpp)

target_include_directories(montecpp PRIVATE include)
