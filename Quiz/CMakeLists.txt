cmake_minimum_required(VERSION 3.17)
project(Quiz)

set(CMAKE_CXX_STANDARD 20)

add_executable(Quiz quizApp.cpp quizFunc.cpp quizFunc.h)