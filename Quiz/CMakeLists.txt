cmake_minimum_required(VERSION 3.17)
project(Quiz)

set(CMAKE_CXX_STANDARD 20)

add_executable(Quiz quizApp.cpp structsNconstants.h basicFuncs.cpp basicFuncs.h contentEditors.cpp contentEditors.h
        questionProcessing.cpp questionProcessing.h gameUtilities1.cpp gameUtilities1.h gameUtilities2.cpp gameUtilities2.h
               printMenus.cpp printMenus.h lifelinesFuncs.cpp lifelinesFuncs.h)

