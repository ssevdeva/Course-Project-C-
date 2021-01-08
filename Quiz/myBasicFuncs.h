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

#ifndef QUIZ_MYBASICFUNCS_H
#define QUIZ_MYBASICFUNCS_H

#include <iostream>
#include "Resources/termcolor.hpp"
#include <string>
#include <random>

#include "myConstants.h"
using namespace std;

void Print(Position pos, const string &s, int linelength);

void Border();

void TitleBar();

void GetWholeQuestion(string& str);

void GetWholeAnswer(string& str);

string GenerateID(const char& topic, int lvl);


#endif //QUIZ_MYBASICFUNCS_H
