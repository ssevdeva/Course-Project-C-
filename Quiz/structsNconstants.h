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
* <header file with helper constants and structs>
*
*/

#ifndef QUIZ_STRUCTSNCONSTANTS_H
#define QUIZ_STRUCTSNCONSTANTS_H

#define GEO_SRC "Resources/geography.txt"
#define HIST_SRC "Resources/history.txt"
#define LIT_SRC "Resources/literature.txt"
#define PHYS_SRC "Resources/physics.txt"
#define POL_SRC "Resources/politics.txt"
#define WORK_SRC "Resources/workFile.txt"

const unsigned int LETTERCASE = 'a' - 'A';

// Length of game field.
const int LINE = 80;

// Game specifications.
const int QUESTIONS_IN_GAME = 15;

// Categories limits.
const int LAST_EASY = 3,
          LAST_MILD = 7,
          LAST_HARD = 10;

// Game stages.
const int FIRST_STAGE = 5,
          SECOND_STAGE = 10,
          LAST_STAGE = 15;

// Prizing stages.
const int STAGE1 = 3,
          STAGE2 = 11,
          STAGE3 = 14;

// Game prizes.
const int INITIAL_PRIZE = 100,
          FORTH_PRIZE = 500,
          TWELFTH_PRIZE = 125000,
          THE_GRAND_MILLION = 1000000;



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
    std::string questText,
            ansA,
            ansB,
            ansC,
            ansD;
    char answer;
};

#endif //QUIZ_STRUCTSNCONSTANTS_H
