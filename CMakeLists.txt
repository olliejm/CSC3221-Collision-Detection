cmake_minimum_required(VERSION 3.8)
project(CSC3221_Project_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Shape.cpp Shape.h Circle.cpp Circle.h Square.cpp Square.h Game.cpp CollisionManager.cpp CollisionManager.h GameEngine.cpp GameEngine.h)
add_executable(CSC3221_Project_2 ${SOURCE_FILES})