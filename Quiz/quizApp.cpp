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

#include <iostream>
#include "Resources/termcolor.hpp"
#include <string>
#include <fstream>
#include <cstdlib>

#include "myConstants.h"
#include "myBasicFuncs.h"
#include "myContentEditors.h"

using namespace std;

/*
 * MainMenuPrint() function displays main menu options on the console.
 */
void MainMenuPrint() {
    TitleBar();
    cout << '\n';
    cout << termcolor::color<SPRING_GREEN>;
    Print(CENTER, "N - New Game\n", LINE);
    Print(CENTER, "A - Add Question\n", LINE);
    Print(CENTER, "M - Modify Question\n", LINE);
    Print(CENTER, "E - Exit\n\n", LINE);
}

/*
 * MainMenuOption() function asks the user to input their choice.
 */
void MainMenuOption(Option &choice) {
    const unsigned int LETTERCASE = 'a' - 'A';

    int valid = 0;
    char opt;

    while (valid != 1) {
        if (valid < 0) {
            Border();
            MainMenuPrint();
            cout << termcolor::color<INDIAN_RED>;
            Print(CENTER, "Invalid choice!\n", LINE);
            Print(CENTER, "Please, enter valid selection: ", LINE);
        }
        else {
            cout << termcolor::color<SPRING_GREEN>;
            Print(CENTER, "Enter selection: ", LINE);
        }
        cin >> opt;
        switch (opt) {
            case NewGame:
            case NewGame + LETTERCASE: {
                choice = NewGame;
                valid = 1;
            }
                break;
            case AddQ :
            case AddQ + LETTERCASE: {
                choice = AddQ;
                valid = 1;
            }
                break;
            case ModifyQ :
            case ModifyQ + LETTERCASE: {
                choice = ModifyQ;
                valid = 1;
            }
                break;
            case ExitGame :
            case ExitGame + LETTERCASE: {
                choice = ExitGame;
                valid = 1;
            }
                break;
            default: {
                --valid;
                cin.clear();
                cin.ignore();
            }
        }
    }
    cout << '\n';
    Border();
}

void MainMenu();   // The function is to be used afterwards.

/*
 * CategoriesPrint() function displays question categories on the console.
 */
void CategoriesPrint() {
    TitleBar();
    cout << '\n';
    cout << termcolor::color<SPRING_GREEN>;
    Print(CENTER, "1. Geography\n", LINE);
    Print(CENTER, "2. History\n", LINE);
    Print(CENTER, "3. Literature\n", LINE);
    Print(CENTER, "4. Physics\n", LINE);
    Print(CENTER, "5. Politics\n", LINE);
    cout << '\n';
    Print(CENTER, "6. All Categories\n\n", LINE);
}

/*
 * CategoriesOption() function asks the user to input their choice of topic.
 */
void CategoriesOption(Category &topic) {
    int valid = 0;
    int opt;

    while (valid != 1) {
        if (valid < 0) {
            Border();
            CategoriesPrint();
            cout << termcolor::color<INDIAN_RED>;
            Print(CENTER, "Invalid choice!\n", LINE);
            Print(CENTER, "Please, enter valid selection: ", LINE);
        }
        else {
            cout << termcolor::color<SPRING_GREEN>;
            Print(CENTER, "Enter selection: ", LINE);
        }
        cin >> opt;
        switch (opt) {
            case Geography: {
                topic = Geography;
                valid = 1;
            }
                break;
            case History: {
                topic = History;
                valid = 1;
            }
                break;
            case Literature: {
                topic = Literature;
                valid = 1;
            }
                break;
            case Physics: {
                topic = Physics;
                valid = 1;
            }
                break;
            case Politics: {
                topic = Politics;
                valid = 1;
            }
                break;
            case All: {
                topic = All;
                valid = 1;
            }
                break;
            default: {
                --valid;
                cin.clear();
                cin.ignore();
            }
        }
    }
    cout << '\n';
    Border();
}

/*
 * ChooseCategory() function displays all categories and gets user's choice of topic.
 */
void ChooseCategory() {
    Category topic;
    CategoriesPrint();
    CategoriesOption(topic);
}

/*
 * Redirect() function returns the user to the main menu.
 */
void Redirect(){
    char key;
    Print(CENTER, "Press any key and ENTER continue...", LINE);
    cout << '\n';
    cin >> key;
    MainMenu();
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
        Print (CENTER, "Sorry, the question could not be added!", LINE);
        Redirect();
        return;
    }
}

/*
 * Substitute() function gets the info for the question with a number idNum
 * that needs to be modified and adds it to the corresponding source file.
 */
void Substitute(const string& idNum) {
    int level;
    char topic;
    string question,
            pathName;

    // Read the new information about the question.
    TakeQuestionInfo(level, topic, question, (string &) pathName);

    // Question's ID number remains unchanged.
    string myText = idNum + "\n" + question;

    // Add the modified question to the source file for its category.
    if (AddContent((string &) pathName, myText, level)) {
        cout << termcolor::color<SPRING_GREEN>;
        Print(CENTER, "The question has been successfully modified!\n", LINE);
        Redirect();
        return;
    }

    // Display a message, if the process has failed.
    cout << termcolor::color<INDIAN_RED>;
    Print(CENTER, "Sorry, the question could not be modified!\n", LINE);
    Redirect();
}

/*
 * ModifyQuestion() searches for an existing question and modifies its information.
 */
void ModifyQuestion() {
    string idNum;

    // Choose a question ID number.
    cout << termcolor::color<SPRING_GREEN>;
    Print(CENTER, "Please, enter the ID number of the question: ", LINE);
    cin >> idNum;
    cout << "\n";

    // Check if the question exists among the source files for each category.
    if (SearchFile(idNum, GEO_SRC)) {
        Substitute(idNum);                      // start modification
    }
    if (SearchFile(idNum, HIST_SRC)) {
        Substitute(idNum);                      // start modification
    }
    if (SearchFile(idNum, LIT_SRC)) {
        Substitute(idNum);                      // start modification
    }
    if (SearchFile(idNum, PHYS_SRC)) {
        Substitute(idNum);                      // start modification
    }
    if (SearchFile(idNum, POL_SRC)) {
        Substitute(idNum);                      // start modification
    }

    // Display a message if the question does not exist.
    cout << termcolor::color<INDIAN_RED>;
    Print(CENTER, "The question does not exist!", LINE);
    cout << termcolor::color<SPRING_GREEN>;
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
        case AddQ: {
            AddQuestion();
        }
            break;
        case NewGame:
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