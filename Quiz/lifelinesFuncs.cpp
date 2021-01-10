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
* <file with helper functions necessary for the use of lifelines in the game>
*
*/

#include <iostream>
#include "Resources/termcolor.hpp"
#include <string>

#include "structsNconstants.h"
#include "basicFuncs.h"
#include "printMenus.h"
#include "questionProcessing.h"
#include "gameTools2.h"

/*
 * FiftyFifty() function simulates the "50:50" lifeline.
 * Eliminates two out of three wrong questions and displays the two answer options left.
 */
void FiftyFifty(const Question& thisQuestion, const int questNum) {
    struct MyAnswer {
        bool display;
        unsigned int num;
        char letter;
    };
    MyAnswer ansA {
            false, 1, 'A'
    };
    MyAnswer ansB {
            false, 2, 'B'
    };
    MyAnswer ansC {
            false, 3, 'C'
    };
    MyAnswer ansD {
            false, 4, 'D'
    };

    unsigned int correctAns = 0,
                 wrongAns = 0;

    if (thisQuestion.answer == ansA.letter) {    // Check if this is the correct answer.
        ansA.display = true;
        correctAns = ansA.num;
    }
    else {
        if (thisQuestion.answer == ansB.letter) {    // Check if this is the correct answer.
            ansB.display = true;
            correctAns = ansB.num;
        }
        else {
            if (thisQuestion.answer == ansC.letter) {    // Check if this is the correct answer.
                ansC.display = true;
                correctAns = ansC.num;
            }
            else {
                ansD.display = true;
                correctAns = ansD.num;
            }
        }
    }

    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(ansA.num, ansD.num);

    // Generate new random numbers until the generated is not the correct answer.
    wrongAns = distrib(gen);
    while (wrongAns == correctAns) {
        wrongAns = distrib(gen);
    }

    if (wrongAns == ansA.num) {           // Check if this is the wrong answer to be displayed.
        ansA.display = true;
    }
    else {
        if (wrongAns == ansB.num) {           // Check if this is the wrong answer to be displayed.
            ansB.display = true;
        }
        else {
            if (wrongAns == ansC.num) {           // Check if this is the wrong answer to be displayed.
                ansC.display = true;
            }
            else {
                ansD.display = true;
            }
        }
    }
    // Display the question with a reduced number of answer options.
    PrintQuestion(questNum, thisQuestion, ansA.display, ansB.display, ansC.display, ansD.display);
}

void AskPublic(const Question& thisQuestion, const int questNum) {

}

/*
 * FriendCall() function simulates the "Phone a friend" lifeline.
 * Generates a possible answer according to a friend's opinion.
 */
void FriendCall() {
    struct MyAnswer {
        unsigned int num;
        string letter;
    };
    MyAnswer ansA {
            1, "A"
    };
    MyAnswer ansB {
            2, "B"
    };
    MyAnswer ansC {
            3, "C"
    };
    MyAnswer ansD {
            4, "D"
    };

    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(ansA.num, ansD.num);

    unsigned int randomNum = distrib(gen);

    // Initialisation of guessing.
    MyAnswer guess {
            randomNum, "A"
    };

    if (guess.num == ansB.num) {               // Check if this is the answer guessed.
        guess.letter = ansB.letter;
    }
    else {
        if (guess.num == ansC.num) {               // Check if this is the answer guessed.
            guess.letter = ansC.letter;
        }
        else {
            if (guess.num == ansD.num) {               // Check if this is the answer guessed.
                guess.letter = ansD.letter;
            }
        }
    }
    // Display friend's opinion.

    cout << termcolor::color<SPRING_GREEN>;
    Print(CENTER, "I suppose the correct answer is ", LINE);
    cout << termcolor::color<CHARTEUSE> << guess.letter << termcolor::color<SPRING_GREEN> << ".\n";
    cout << termcolor::reset;
    cout << '\n';
}

/*
 * Lifelines() function calls each lifeline function
 * according to the user's choice of a lifeline.
 */
void Lifelines(const Question& temp, const int questNum, bool& fiftyFifty, bool& askPublic, bool& friendCall) {
    string str_fiftyFifty = "1. 50:50",
            str_askPublic = "2. Ask the Audience",
            str_friendCall = "3. Phone a Friend";

    // Check if all lifelines have already been used.
    if (fiftyFifty and askPublic and friendCall) {
        return;
    }

    // Display a message to the user.
    cout << termcolor::white;
    Print(CENTER, "Would you like to use any lifelines?\n", LINE);
    Print(CENTER, "Y - Yes/No - N: ", LINE);

    // Process user's choice.
    string yes_no;
    cin >> yes_no;

    // Handle invalid input.
    while (!(yes_no == "Y" or yes_no == "y" or yes_no == "N" or yes_no == "n")) {
        cin.ignore();
        cin.clear();
        cin >> yes_no;
    }

    cout << '\n';
    if (yes_no == "N" or yes_no == "n") {
        cout << termcolor::reset;
        return;
    }
    if (!fiftyFifty) {                                 // Check if the lifeline is available.
        Print(CENTER, str_fiftyFifty, LINE);
        cout << '\n';
    }
    if (!askPublic) {                                 // Check if the lifeline is available.
        Print(CENTER, str_askPublic, LINE);
        cout << '\n';
    }
    if (!friendCall) {                                 // Check if the lifeline is available.
        Print(CENTER, str_friendCall, LINE);
        cout << '\n';
    }
    cout << '\n';

    // Process user's choice.
    Print(CENTER, "Enter choice: ", LINE);
    string choice;
    cin >> choice;

    // Handle invalid input.
    while (!(choice == "1" or choice == "2" or choice == "3")) {

        cout << '\n' << termcolor::color<INDIAN_RED>;
        Print(CENTER, "Invalid choice of lifeline!\n", LINE);
        Print(CENTER, "Please, enter an available number of a lifeline: ", LINE);
        cin >> choice;
        cout << termcolor::white;
    }

    cout << '\n';
    if (choice == "1") {                      // Check if this is the lifeline of choice.
        fiftyFifty = true;                    // Set lifeline to already used.
        FiftyFifty(temp, questNum);           // Use lifeline.
        return;
    }
    /*if (choice == "2") {                      // Check if this is the lifeline of choice.
        askPublic = true;                       // Set lifeline to already used.
        AskPublic(temp, questNum); b            // Use lifeline.
        return;
    } */
    if (choice == "3") {                      // Check if this is the lifeline of choice.
        friendCall = true;                    // Set lifeline to already used.
        FriendCall();                         // Use lifeline.
        return;
    }
}