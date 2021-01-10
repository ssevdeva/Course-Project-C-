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
* <header file with helper functions reading, saving and printing the information for a new question>
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

void PrintQuestion(int num, const Question& temp, bool ansA,
                   bool ansB, bool ansC, bool ansD);

#endif //QUIZ_MYTAKEQUESTIONFUNC_H
