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
* <header file with helper functions necessary for the use of lifelines in the game>
*
*/

#ifndef QUIZ_LIFELINESFUNCS_H
#define QUIZ_LIFELINESFUNCS_H

#include <iostream>
#include <string>

#include "structsNconstants.h"
#include "basicFuncs.h"
#include "printMenus.h"
#include "questionProcessing.h"
#include "gameUtilities2.h"

void FiftyFifty(const Question& thisQuestion, int questNum);

void AskPublic(const Question& thisQuestion, int questIndex);

void FriendCall();

void Lifelines(const Question& temp, int questNum, bool& fiftyFifty, bool& askPublic, bool& friendCall);


#endif //QUIZ_LIFELINESFUNCS_H
