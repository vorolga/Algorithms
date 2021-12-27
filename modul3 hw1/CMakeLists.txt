cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp IGraph.h ListGraph.h MatrixGraph.h SetGraph.h ArcGraph.h ListGraph.cpp MatrixGraph.cpp SetGraph.cpp ArcGraph.cpp)
