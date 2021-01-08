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
#include <string>
#include <cstring>
#include <fstream>

#include "myConstants.h"
#include "myTakeQuestionFunc.h"

using namespace std;

bool AddContent(string& myPath, const string& myText, int level);

bool RemoveQuestion(const string& pathName, const string& startPoint);

bool SearchFile(const string& myText, const string& pathName);

#endif //QUIZ_MYCONTENTEDITORS_H
