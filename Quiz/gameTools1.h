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
* <INSERT DESCRIPTION HERE>
*
*/

#ifndef QUIZ_GAMETOOLS1_H
#define QUIZ_GAMETOOLS1_H

#include <iostream>
#include <string>

#include "structsNconstants.h"
#include "contentEditors.h"

void GetLevel(int lvl, ifstream &ReadFile, ofstream &WriteFile, int &numOfQuest);

bool GatherAllQuestions(string &newFilePath, int &easy, int &mild, int &hard);

bool GatherQuestions(Category choice, string &newFilePath, int &easy, int &mild, int &hard);

#endif //QUIZ_GAMETOOLS1_H
