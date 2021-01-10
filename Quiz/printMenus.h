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
* <header file with helper functions displaying menus in the console>
*
*/

#include <iostream>
#include "Resources/termcolor.hpp"

#include "structsNconstants.h"
#include "basicFuncs.h"

#ifndef QUIZ_PRINTMENUS_H
#define QUIZ_PRINTMENUS_H


void MainMenuPrint();

void MainMenuOption(Option &choice);

void CategoriesPrint();

void CategoriesOption(Category &topic);

void ChooseCategory(Category &topic);

#endif //QUIZ_PRINTMENUS_H
