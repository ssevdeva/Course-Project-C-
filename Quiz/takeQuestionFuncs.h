/**
*
* Solution to course project # 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Sanya Sevdeva
* @idnumber 62517
* @compiler GCC
*
* <file with helper functions>
*
*/

#include <iostream>
#include "Resources/termcolor.hpp"
#include <string>

#include "structsNconstants.h"
#include "basicFuncs.h"

using namespace std;

#ifndef QUIZ_MYTAKEQUESTIONFUNC_H
#define QUIZ_MYTAKEQUESTIONFUNC_H

void ValidAnswer(string &answer);

void TakeQuestionInfo(int& level, char& topicSmbl, string& question, string& sourceFile);

#endif //QUIZ_MYTAKEQUESTIONFUNC_H
