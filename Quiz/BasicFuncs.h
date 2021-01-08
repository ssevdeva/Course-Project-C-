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

#ifndef QUIZ_BASICFUNCS_H
#define QUIZ_BASICFUNCS_H

#include <iostream>
#include "Resources/termcolor.hpp"
#include <string>
#include <random>

#include "Structs_Constants.h"
using namespace std;

void Print(Position pos, const string &s, int linelength);

void Border();

void TitleBar();

void GetWholeQuestion(string& str);

void GetWholeAnswer(string& str);

string GenerateID(const char& topic, int lvl);


#endif //QUIZ_BASICFUNCS_H
