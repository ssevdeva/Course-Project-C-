cmake_minimum_required(VERSION 3.17)
project(Quiz)

set(CMAKE_CXX_STANDARD 20)

add_executable(Quiz quizApp.cpp Structs_Constants.h BasicFuncs.cpp BasicFuncs.h ContentEditors.cpp ContentEditors.h TakeQuestionFunc.cpp TakeQuestionFunc.h)

