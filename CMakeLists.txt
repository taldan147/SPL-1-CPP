cmake_minimum_required(VERSION 3.17)
project(Assignment1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Assignment1 src/main.cpp src/Session.cpp src/Graph.cpp src/JsonReader.cpp src/Agent.cpp src/Tree.cpp src/Tester.cpp)