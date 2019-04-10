cmake_minimum_required(VERSION 3.13)
project(kds)

set(CMAKE_CXX_STANDARD 14)

add_executable(kds main.cpp FordFulkerson.cpp FordFulkerson.h EdmondCarp.cpp EdmondCarp.h)