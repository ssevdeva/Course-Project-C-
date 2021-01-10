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
* <MAIN PROJECT FILE>
*
*/

#include <iostream>
#include "Resources/termcolor.hpp"
#include <string>
#include <cstdlib>

#include "structsNconstants.h"
#include "basicFuncs.h"
#include "printMenus.h"
#include "contentEditors.h"
#include "questionProcessing.h"
#include "gameTools1.h"
#include "gameTools2.h"
#include "lifelinesFuncs.h"

using namespace std;

void MainMenu();   // The function is to be used afterwards.

/*
 * Redirect() function returns the user to the main menu.
 */
void Redirect() {
    Print(CENTER, "Press ENTER to continue...\n", LINE);
    cin.ignore(LINE, '\n');
    cin.get();
    MainMenu();  // return to the main menu
}

void StartGame() {
    string newFile;
    int easy = 0, // will store the number of easy questions (lvl. 1 - 3)
        mild = 0, // will store the number of mild questions (lvl. 4 - 7)
        hard = 0; // will store the number of difficult questions (lvl. 8 - 10)

    Category choice;
    ChooseCategory(choice);

    TitleBar();

    if (GatherQuestions(choice, newFile, easy, mild, hard)) {

        if (easy < FIRST_STAGE or mild < FIRST_STAGE or hard < FIRST_STAGE) {
            cout << termcolor::color<INDIAN_RED> << '\n';
            Print(CENTER, "Sorry, there are not enough questions to start a game!\n", LINE);
            cout << termcolor::color<SPRING_GREEN>;

            // Remove the file with the question that had to be deleted.
            char workFile[newFile.length()];
            strcpy(workFile, newFile.c_str());
            if (remove(workFile) == 0) {
                Redirect();
                return;
            }
        }

        Question currentQuestion;
        bool isCorrect = true,
             fiftyFifty = false,
             askPublic = false,
             friendCall = false;
        int questNum;
        int askedQuestions[QUESTIONS_IN_GAME];
        int prize = 0;

        for (questNum = 1; (questNum <= FIRST_STAGE and isCorrect); ++questNum) {
            if (ReadQuestion(newFile, currentQuestion, questNum, "EASY", easy, askedQuestions)) {
                PrintQuestion(questNum, currentQuestion, true,true,true,true);
                Lifelines(currentQuestion, questNum, fiftyFifty, askPublic, friendCall);
                if (!TakeAnswer(currentQuestion, questNum, prize)) {
                    isCorrect = false;
                }


            }
        }
        for (questNum = 6; (questNum <= SECOND_STAGE and isCorrect); ++questNum) {
            if (ReadQuestion(newFile, currentQuestion, questNum, "MILD", mild, askedQuestions)) {
                PrintQuestion(questNum, currentQuestion, true,true,true,true);
                Lifelines(currentQuestion, questNum, fiftyFifty, askPublic, friendCall);
                if (!TakeAnswer(currentQuestion, questNum, prize)) {
                    isCorrect = false;
                }
            }
        }
        for (questNum = 11; (questNum <= LAST_STAGE and isCorrect); ++questNum) {
            if (ReadQuestion(newFile, currentQuestion, questNum, "HARD", hard, askedQuestions)) {
                PrintQuestion(questNum, currentQuestion, true,true,true,true);
                Lifelines(currentQuestion, questNum, fiftyFifty, askPublic, friendCall);
                if (!TakeAnswer(currentQuestion, questNum, prize)) {
                    isCorrect = false;
                }
            }
        }
        // Remove the file with the question that had to be deleted.
        char workFile[newFile.length()];
        strcpy(workFile, newFile.c_str());
        if (remove(workFile) == 0) {
            Redirect();
            return;
        }
    }
}


/*
 * AddQuestion() adds a new question in a category.
 */
void AddQuestion() {
    int level;
    char topicSmbl;
    string question,
           sourceFile;

    TakeQuestionInfo(level, topicSmbl, question, sourceFile);

    // Generate an ID number for the new question and add it to question variable.
    string addText = GenerateID(topicSmbl, level) + "\n" + question;

    // Add all the info for the new question to the corresponding sourceFile if possible.
    if (AddContent(sourceFile, addText, level)) {
        cout << termcolor::color<SPRING_GREEN> << '\n';
        Print(CENTER, "The question has been successfully added!\n", LINE);
        Redirect();
    }
    else {
        cout << termcolor::color<INDIAN_RED>;
        Print(CENTER, "Sorry, the question could not be added!", LINE);
        Redirect();
        return;
    }
}

/*
 * ModifyQuestion() searches for an existing question and modifies its information.
 */
void ModifyQuestion() {
    string idNum;
    bool doExist = false;

    while (!doExist) {
        // Choose a question ID number.
        cout << termcolor::color<SPRING_GREEN>;
        Print(CENTER, "Please, enter the ID number of the question: ", LINE);
        cin >> idNum;
        cout << "\n";

        // Check if the question exists among the source files for each category.
        if (SearchFile(idNum, GEO_SRC)) {
            doExist = true;
            Substitute(idNum);                      // start modification
            Redirect();
        }
        if (SearchFile(idNum, HIST_SRC)) {
            doExist = true;
            Substitute(idNum);                      // start modification
            Redirect();
        }
        if (SearchFile(idNum, LIT_SRC)) {
            doExist = true;
            Substitute(idNum);                      // start modification
            Redirect();
        }
        if (SearchFile(idNum, PHYS_SRC)) {
            doExist = true;
            Substitute(idNum);                      // start modification
            Redirect();
        }
        if (SearchFile(idNum, POL_SRC)) {
            doExist = true;
            Substitute(idNum);                      // start modification
            Redirect();
        }

        // Display a message if the question does not exist.
        cout << termcolor::color<INDIAN_RED>;
        Print(CENTER, "The question does not exist!", LINE);
        cout << termcolor::color<SPRING_GREEN>;
    }
    Redirect();
}

/*
 * ExitFunc() function displays a final message and terminates the game.
 */
void ExitFunc() {
    cout << termcolor::white;
    Print(CENTER, "Thank you for playing! :)", LINE);
    cout << '\n';
    exit(EXIT_SUCCESS);
}

/*
 * MainMenu() function displays main menu and gets user's choice.
 */
void MainMenu() {
    Option choice;
    MainMenuPrint();
    MainMenuOption(choice);
    switch (choice) {
        case AddQ:
            AddQuestion();
            break;
        case NewGame:
            StartGame();
            break;
        case ModifyQ:
            ModifyQuestion();
            break;
        case ExitGame:
            ExitFunc();
            break;
    }
}

int main() {
    MainMenu();
    return 0;
}