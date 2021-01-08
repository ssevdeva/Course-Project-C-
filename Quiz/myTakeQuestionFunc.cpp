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

#include <iostream>
#include "Resources/termcolor.hpp"
#include <string>

#include "myConstants.h"
#include "myBasicFuncs.h"

using namespace std;

/*
 * TakeQuestionInfo() function asks the user to enter a question and saves the input info.
 */
void TakeQuestionInfo(int& level, char& topicSmbl, string& question, string& sourceFile) {
    int topic;
    string answer;
    string ansA,
            ansB,
            ansC,
            ansD;

    // Choose a question category.
    cout << termcolor::color<SPRING_GREEN>;
    Print(CENTER, "Choose a category for the question", LINE);
    cout << "\n\n";
    Print(CENTER, "1. Geography  2. History  3. Literature  4. Physics  5. Politics  \n\n", LINE);
    Print(CENTER, "Enter: ", LINE);

    cin >> topic;

    // Handle invalid input.
    while (topic < 1 or topic > 5 or cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << termcolor::color<INDIAN_RED> << '\n';
        Print(CENTER, "Invalid choice!\n", LINE);
        Print(CENTER, "Please, enter valid selection: ", LINE);
        cin >> topic;
    }
    cout << '\n';

    // Choose a source text file according to the selected category.
    switch (topic) {
        case Geography: {
            topicSmbl = 'g';
            sourceFile = GEO_SRC;
        }
            break;
        case History: {
            topicSmbl = 'h';
            sourceFile = HIST_SRC;
        }
            break;
        case Literature: {
            topicSmbl = 'l';
            sourceFile = LIT_SRC;
        }
            break;
        case Physics: {
            topicSmbl = 'p';
            sourceFile = PHYS_SRC;
        }
            break;
        case Politics: {
            topicSmbl = 'P';
            sourceFile = POL_SRC;
        }
            break;
        default:
            break;
    }

    // Choose a question category.
    cout << termcolor::color<SPRING_GREEN>;
    Print(CENTER, "Choose a level of difficulty (1 - 10): ", LINE);
    cin >> level;

    // Handle invalid input.
    while (level < 1 or level > 10 or cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << termcolor::color<INDIAN_RED> << '\n';
        Print(CENTER, "Invalid choice!\n", LINE);
        Print(CENTER, "Please, enter valid selection: ", LINE);
        cin >> level;
    }
    cout << '\n';

    // Enter a new question.
    cout << termcolor::color<SPRING_GREEN>;
    Print(CENTER, "Please, enter your question: \n", LINE);
    GetWholeQuestion(question);

    // Enter optional answers for the question.
    cout << termcolor::color<SPRING_GREEN>;
    Print(CENTER, "Please, enter the answers: \n", LINE);
    cout << "A) ";
    GetWholeAnswer(ansA);
    ansA = "A) " + ansA;
    cout << "B) ";
    GetWholeAnswer(ansB);
    ansB = "B) " + ansB;
    cout << "C) ";
    GetWholeAnswer(ansC);
    ansC = "C) " + ansC;
    cout << "D) ";
    GetWholeAnswer(ansD);
    ansD = "D) " + ansD;

    // Choose the correct answer.
    cout << "Correct answer: ";
    cin >> answer;

    // Handle invalid input.
    while (!(answer == "A" or answer == "B" or answer == "C" or answer == "D")) {
        cin.clear();
        cin.ignore();
        cout << termcolor::color<INDIAN_RED> << '\n';
        Print(CENTER, "Invalid choice!\n", LINE);
        Print(CENTER, "Please, enter valid selection: ", LINE);
        cin >> answer;
    }

    // Insert a '*' in front of the correct answer.
    switch (answer[0]) {
        case 'A': {
            ansA = '*' + ansA;
        }
            break;
        case 'B': {
            ansB = '*' + ansB;
        }
            break;
        case 'C': {
            ansC = '*' + ansC;
        }
            break;
        case 'D': {
            ansD = '*' + ansD;
        }
            break;
        default:
            break;
    }
    // Save the question and the answers for it in question variable.
    question = question + "\n" + ansA + "\n" + ansB + "\n" + ansC + "\n" + ansD + "\n";
    Border();
}
