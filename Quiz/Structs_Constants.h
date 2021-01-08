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
* <header file with helper functions>
*
*/

#ifndef QUIZ_STRUCTS_CONSTANTS_H
#define QUIZ_STRUCTS_CONSTANTS_H

#define GEO_SRC "Resources/geography.txt"
#define HIST_SRC "Resources/history.txt"
#define LIT_SRC "Resources/literature.txt"
#define PHYS_SRC "Resources/physics.txt"
#define POL_SRC "Resources/politics.txt"
#define WORK_SRC "Resources/workFile.txt"

const int INDIAN_RED = 203;
const int SPRING_GREEN = 121;
const int TURQUOISE = 45;
const int LINE = 80;
const int gameQuestions = 15;

enum Option {
    NewGame = 'N', AddQ = 'A', ModifyQ = 'M', ExitGame = 'E'
};
enum Category {
    Geography = 1, History, Literature, Physics, Politics, All
};
enum Position {
    LEFT, CENTER, RIGHT
};

struct Question {
    std::string quesText,
            ansA,
            ansB,
            ansC,
            ansD;
    char answer;
};

#endif //QUIZ_STRUCTS_CONSTANTS_H
