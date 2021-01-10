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
* <header file with helper functions necessary for the implementation of the "New Game" functionality>
*
*/

#include <iostream>
#include "Resources/termcolor.hpp"
#include <string>
#include <iomanip>

#include "structsNconstants.h"
#include "basicFuncs.h"
#include "contentEditors.h"

#ifndef QUIZ_GAMETOOLS2_H
#define QUIZ_GAMETOOLS2_H

bool IsElement(int elmnt, const int elemsArr[QUESTIONS_IN_GAME], int questNum);

bool ReadQuestion(const string &srcFile, Question &temp, int questNum, const string &complexity,
                  int questsAvailable, int (&asked)[QUESTIONS_IN_GAME]);

bool TakeAnswer(const Question& temp, int questNum, int &moneyGained);

#endif //QUIZ_GAMETOOLS2_H
