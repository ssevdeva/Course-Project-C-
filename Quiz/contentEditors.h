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
* <header file with helper functions committing changes to the content of source text files>
*
*/

#ifndef QUIZ_CONTENTEDITORS_H
#define QUIZ_CONTENTEDITORS_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include "structsNconstants.h"
#include "questionProcessing.h"

using namespace std;

bool AddContent(string& myPath, const string& myText, int level);

bool RemoveQuestion(const string& pathName, const string& startPoint);

bool SearchFile(const string& myText, const string& pathName);

void Substitute(const string &idNum);

#endif //QUIZ_CONTENTEDITORS_H
