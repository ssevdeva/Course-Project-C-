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
* <file with helper functions necessary for the implementation of the "New Game" functionality>
*
*/

#include <iostream>
#include "Resources/termcolor.hpp"
#include <string>
#include <iomanip>

#include "structsNconstants.h"
#include "basicFuncs.h"
#include "contentEditors.h"

/*
 * IsElement() function checks if the user has already been given a specific question.
 */
bool IsElement(const int elmnt, const int elemsArr[QUESTIONS_IN_GAME], const int questNum) {
    int begin = 0,
        end = 0;

    // Define the current stage of the game and limits of question search.
    if (questNum <= FIRST_STAGE) {
        begin = 0;
        end = questNum - 1;
    }

    // Define the current stage of the game and limits of question search.
    if (questNum > FIRST_STAGE and questNum <= SECOND_STAGE) {
        begin = FIRST_STAGE;
        end = questNum - 1;
    }

    // Define the current stage of the game and limits of question search.
    if (questNum > SECOND_STAGE) {
        begin = SECOND_STAGE;
        end = LAST_STAGE;
    }

    // Start searching for the current question index.
    for (int i = begin; i < end; ++i) {
        if (elmnt == elemsArr[i]) {
            return true;
        }
    }
    return false;
}

/*
 * ReadQuestion() function generates a random question number and unless the user
 * has already been given this question, saves the information about it in temp.
 */
bool ReadQuestion(const string &srcFile, Question &temp, int questNum, const string &complexity,
                  const int questsAvailable, int (&asked)[QUESTIONS_IN_GAME]) {
    string line;

    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(1, questsAvailable);

    // Check if the generated question has already been given.
    int thisQuestion = distrib(gen);
    while (IsElement(thisQuestion, asked, questNum)) {
        thisQuestion = distrib(gen);
    }
    asked[questNum - 1] = thisQuestion;

    // Open the current source file.
    ifstream ReadFile;
    ReadFile.open(srcFile, ios::in);
    if (!ReadFile.is_open()) {
        return false;
    }

    // Read lines until searched question is reached.
    getline(ReadFile, line);
    while (!(line == complexity or ReadFile.eof())) {
        getline(ReadFile, line);
    }

    if (line == complexity) {
        while (line != to_string(thisQuestion)) {
            getline(ReadFile, line);
        }
    }

    // Start reading question's components.
    if (line == to_string(thisQuestion)) {
        getline(ReadFile, line); // ID number
        temp.questText = "";
        getline(ReadFile, line);
        while (!((line[0] == 'A' and line[1] == ')') or line[0] == '*')) {
            temp.questText += line;
            getline(ReadFile, line);
        }
        if (line[0] == '*') {
            temp.answer = 'A';
            temp.ansA = line.substr(1);
        }
        else {
            temp.ansA = line;
        }
        getline(ReadFile, line);
        if (line[0] == '*') {
            temp.answer = 'B';
            temp.ansB = line.substr(1);
        }
        else {
            temp.ansB = line;
        }
        getline(ReadFile, line);
        if (line[0] == '*') {
            temp.answer = 'C';
            temp.ansC = line.substr(1);
        }
        else {
            temp.ansC = line;
        }
        getline(ReadFile, line);
        if (line[0] == '*') {
            temp.answer = 'D';
            temp.ansD = line.substr(1);
        }
        else {
            temp.ansD = line;
        }
        ReadFile.close();
        return true;
    }
    return false;
}

/*
 * TakeAnswer() function asks the user to input their number
 * and if it is true, increases the size of their prize.
 */
bool TakeAnswer(const Question& temp, const int questNum, int &moneyGained) {
    string ans;

    cout << termcolor::color<CHARTEUSE>;
    Print(CENTER, "Your answer is: ", LINE);

    // Handle invalid input.
    ValidAnswer(ans);

    // Increase prize if given answer is correct.
    if (ans[0] == temp.answer or ans[0] == temp.answer + LETTERCASE) {
        if (questNum > STAGE1) {
            if ((questNum > STAGE1 + 1 and questNum <= STAGE2) or (questNum > STAGE2 + 1 and questNum <= STAGE3)) {
                moneyGained *= 2;
            } else
                switch (questNum) {
                    case STAGE1 + 1:
                        moneyGained = FORTH_PRIZE;
                        break;
                    case STAGE2 + 1:
                        moneyGained = TWELFTH_PRIZE;
                        break;
                    case STAGE3 + 1:
                        moneyGained = THE_GRAND_MILLION;
                        break;
                    default :
                        break;
                }

        } else {
            moneyGained += INITIAL_PRIZE;
        }
        cout << '\n';
        Print(CENTER, "CONGRATULATIONS!\n", LINE);

        // Display a message and continue.
        if (questNum != LAST_STAGE) {
            Print(CENTER, ("You reached a prize of " + to_string(moneyGained) + "$.\n"), LINE);
            cout << '\n';
            cout << termcolor::color<SPRING_GREEN>;
            Print(CENTER, "Press ENTER to continue...\n", LINE);
            cout << termcolor::color<CHARTEUSE>;
            cin.ignore(LINE, '\n');
            cin.get();
        }
        else {
            // Display a message, if the last stage is completed.
            Print(CENTER, "YOU WON THE GRAND 1, 000, 000$.\n", LINE);
        }
        return true;
    }

    // Display a message, if the given answer is incorrect.
    cout << termcolor::color<INDIAN_RED> << '\n';
    Print(CENTER, "Sorry, the correct answer is ", LINE);
    cout << temp.answer << '.' << '\n';
    cout << termcolor::color<CHARTEUSE> << '\n';

    // Calculate the final sum of money.
    if (questNum <= STAGE1 + 1) {
        moneyGained = 0;
    }
    else {
        if (questNum > STAGE1 + 1 and questNum <= STAGE2 + 1) {
            moneyGained = FORTH_PRIZE;
        }
        else {
            moneyGained = TWELFTH_PRIZE;
        }
    }
    // Display a message at the end of the game.
    Print(CENTER, ("You won a prize of " + to_string(moneyGained) + "$.\n"), LINE);
    cout << termcolor::color<SPRING_GREEN>;
    return false;
}