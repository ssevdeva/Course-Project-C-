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

#ifndef QUIZ_MYCONTENTEDITORS_H
#define QUIZ_MYCONTENTEDITORS_H

#include <iostream>
#include "Resources/termcolor.hpp"
#include <string>

#include "myConstants.h"
#include "myBasicFuncs.h"

using namespace std;

void TakeQuestionInfo(int& level, char& topicSmbl, string& question, string& sourceFile);

bool AddContent(string& myPath, const string& myText, int level);

bool RemoveQuestion(const string& pathName, const string& startPoint);

#endif //QUIZ_MYCONTENTEDITORS_H
