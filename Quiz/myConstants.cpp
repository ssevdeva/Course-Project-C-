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

#define GEO_SRC "Resources/geography.txt"
#define HIST_SRC "Resources/history.txt"
#define LIT_SRC "Resources/literature.txt"
#define PHYS_SRC "Resources/physics.txt"
#define POL_SRC "Resources/politics.txt"
#define WORK_SRC "Resources/workFile.txt"

const int INDIAN_RED = 203;
const int SPRING_GREEN = 121;
const int LINE = 80;

enum Option {
    NewGame = 'N', AddQ = 'A', ModifyQ = 'M', ExitGame = 'E'
};
enum Category {
    Geography = 1, History, Literature, Physics, Politics, All
};
enum Position {
    LEFT, CENTER, RIGHT
};


