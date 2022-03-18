cmake_minimum_required(VERSION 3.0.0)
project(montecpp VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include(CTest)
# enable_testing()

add_executable(montecpp src/main.cpp src/montecarlo.cpp src/tableVisualizer.cpp src/HTMLStubs.cpp)

# add_executable(montecpp src/main.cpp)
target_include_directories(montecpp PRIVATE include)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
