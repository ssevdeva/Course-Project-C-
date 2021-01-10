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

#ifndef QUIZ_GAMEUTILITIES1_H
#define QUIZ_GAMEUTILITIES1_H

#include <iostream>
#include <string>

#include "structsNconstants.h"
#include "contentEditors.h"

void GetLevel(int lvl, ifstream &ReadFile, ofstream &WriteFile, int &numOfQuest);

bool GatherAllQuestions(string &newFilePath, int &easy, int &mild, int &hard);

bool GatherQuestions(Category choice, string &newFilePath, int &easy, int &mild, int &hard);

#endif //QUIZ_GAMEUTILITIES1_H
