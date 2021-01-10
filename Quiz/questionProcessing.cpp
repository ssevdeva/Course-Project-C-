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
* <file with helper functions reading, saving and printing the information for a new question>
*
*/

#include <iostream>
#include <string>

#include "structsNconstants.h"
#include "basicFuncs.h"

using namespace std;

/*
 * IsValidAnswer() function validates an answer letter input.
 */
void ValidAnswer(string &answer) {
    cin >> answer;

    // Handle invalid input.
    while (!(answer == "A" or answer == "a" or answer == "B" or answer == "b" or
             answer == "C" or answer == "c" or answer == "D" or answer == "d")) {
        cin.clear();
        cin.ignore();
        cout << '\n';
        Print(CENTER, "Invalid choice!\n", LINE);
        Print(CENTER, "Please, enter valid selection: ", LINE);
        cin >> answer;
    }
}

/*
 * TakeQuestionInfo() function asks the user to enter a question and saves the input info.
 */
void TakeQuestionInfo(int& level, char& topicSmbl, string& question, string& sourceFile) {
    int topic;
    string answer;
    string  ansA,
            ansB,
            ansC,
            ansD;

    // Choose a question category.
    Print(CENTER, "Choose a category for the question", LINE);
    cout << "\n\n";
    Print(CENTER, "1. Geography  2. History  3. Literature  4. Physics  5. Politics  \n\n", LINE);
    Print(CENTER, "Enter: ", LINE);

    cin >> topic;

    // Handle invalid input.
    while (topic < 1 or topic > 5 or cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << '\n';
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
    Print(CENTER, "Choose a level of difficulty (1 - 10): ", LINE);
    cin >> level;

    // Handle invalid input.
    while (level < 1 or level > 10 or cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << '\n';
        Print(CENTER, "Invalid choice!\n", LINE);
        Print(CENTER, "Please, enter valid selection: ", LINE);
        cin >> level;
    }
    cout << '\n';

    // Enter a new question.
    Print(CENTER, "Please, enter your question: \n", LINE);
    GetWholeQuestion(question);

    // Enter optional answers for the question.
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

    // Handle invalid input.
    ValidAnswer(answer);
    toupper(answer[0]);

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

/*
 * PrintQuestion() function displays the current question together with its number in the game and answers.
 */
void PrintQuestion(const int num, const Question& temp, const bool ansA,
                   const bool ansB, const bool ansC, const bool ansD) {
    Border();
    // display question number
    cout << "Question " + to_string(num) << "\n";

    // display the question
    if (temp.questText.length() > LINE) {                               // multiple lines
        cout << temp.questText.substr(0, LINE - 1) << endl;
        cout << temp.questText.substr(LINE - 1, temp.questText.length() - 1) << "\n\n";
    } else {
        cout << temp.questText << "\n\n";
    }

    // display each answers on a new line if they are too long
    if ((temp.ansA.length() + temp.ansC.length() >= LINE - 2) or
        (temp.ansB.length() + temp.ansD.length() >= LINE - 2)) {
        if (ansA) {                                                    // check if answer has to be displayed
            cout << temp.ansA << "\n";
        }
        if (ansB) {                                                    // check if answer has to be displayed
            cout << temp.ansB<< "\n";
        }
        if (ansC) {                                                    // check if answer has to be displayed
            cout << temp.ansD << "\n";
        }
        if (ansD) {                                                    // check if answer has to be displayed
            cout << temp.ansC << "\n";
        }
    }
    // display each couple of answers on one line if they are short enough
    else {
        if (ansA) {                                                    // check if answer has to be displayed
            cout << temp.ansA;
            for (int i = 0; i < (LINE - temp.ansA.length() - temp.ansC.length() - 2); ++i) {
                cout << ' ';
            }
        }
        else {
            for (int i = 0; i < (LINE - temp.ansC.length() - 2); ++i) {
                cout << ' ';
            }
        }
        if (ansC) {                                                    // check if answer has to be displayed
            cout << temp.ansC << "\n\n";
        }
        else {
            cout << "\n\n";
        }

        if (ansB) {                                                    // check if answer has to be displayed
            cout << temp.ansB;
            for (int i = 0; i < (LINE - temp.ansB.length() - temp.ansD.length() - 2); ++i) {
                cout << ' ';
            }
        }
        else {
            for (int i = 0; i < (LINE - temp.ansD.length() - 2); ++i) {
                cout << ' ';
            }
        }
        if (ansD) {                                                    // check if answer has to be displayed
            cout << temp.ansD << "\n\n";
        }
        else {
            cout << "\n\n";
        }
    }
}
