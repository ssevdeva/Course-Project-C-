cmake_minimum_required(VERSION 3.17)
project(Quiz)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(Quiz quizApp.cpp quizFunc.cpp quizFunc.h)

