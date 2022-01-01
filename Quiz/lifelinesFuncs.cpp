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
#include <string>

#include "structsNconstants.h"
#include "basicFuncs.h"
#include "printMenus.h"
#include "questionProcessing.h"
#include "gameUtilities2.h"

/*
 * GenerateRandom() function generates a random number within a given interval.
 */
int GenerateRandom(const int upper, const int lower) {
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(lower, upper);
    return distrib(gen);
}

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

    unsigned int correctAns,
                 wrongAns;

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

    // Generate new random numbers until the generated is not the correct answer.
    wrongAns = GenerateRandom(ansA.num, ansD.num);
    while (wrongAns == correctAns) {
        wrongAns = GenerateRandom(ansA.num, ansD.num);
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

/*
 * FindCeil() is a utility function to find ceiling of r in arr[l..h].
 */
int FindCeil(int *arr, int r, int l, int h)
{
    int mid;
    while (l < h)
    {
        mid = l + ((h - l) >> 1); // Same as mid = (l+h)/2
        (r > arr[mid]) ? (l = mid + 1) : (h = mid);
    }
    return (arr[l] >= r) ? l : -1;
}

/*
 * MyRand() is a function that returns a random number from arr[]
 * according to distribution array defined by freq[].
 */
int MyRand(const int (&arr)[4], int *freq, int size) {
    // Create and fill prefix array
    int prefix[size],
        i;
    prefix[0] = freq[0];
    for (i = 1; i < size; ++i)
        // Prefix[n-1] is sum of all frequencies.
        prefix[i] = prefix[i - 1] + freq[i];

    // Generate a random number with value from 1 to this sum
    int r = (rand() % prefix[size - 1]) + 1;

    // Find index of ceiling of r in prefix array
    int indexC = FindCeil(prefix, r, 0, size - 1);
    return arr[indexC];
}

/*
 * GenerateQuestionNumber() function randomly generates
 * a question index according to a fixed truth probability.
 */
int GenerateQuestionNumber(const int questIndex, const int (&arr)[4]) {
    const int easyProbability = 70,   // 70% chance of the correct answer to be with the highest vote perc.
              mildProbability = 40,   // 40% chance of the correct answer to be with the highest vote perc.
              hardProbability = 20;   // 20% chance of the correct answer to be with the highest vote perc.

    int correctP,
        wrongP;

    // Define truth probability of first-stage answers.
    if (questIndex <= FIRST_STAGE){
        correctP  = easyProbability / 10,
        wrongP = (100 - easyProbability) / (3 * 10);
    }
    else {
        // Define truth probability of second-stage answers.
        if (questIndex > FIRST_STAGE and questIndex <= SECOND_STAGE) {
            correctP = mildProbability / 10,
            wrongP = (100 - mildProbability) / (3 * 10);
        }
        else {
            // Define truth probability of last-stage answers.
            if (questIndex > SECOND_STAGE){
                correctP  = hardProbability / 10,
                wrongP = (100 - hardProbability) / (3 * 10);
            }
        }
    }
    int freq[4] = {correctP, wrongP, wrongP, wrongP};
    return MyRand(arr, freq, 4);                      // call random index generator
}

/*
 * Initialise() function gives values to a four-element integer array.
 */
void Initialise(int (&arr)[4], const int val1, const int val2, const int val3, const int val4) {
    arr[0] = val1;
    arr[1] = val2;
    arr[2] = val3;
    arr[3] = val4;
}

/*
 * IdIncluded() function checks if an element exists in a four-element integer array.
 */
bool IsIncluded(const int (&arr)[4], const int limit, const int elem) {
    for (int i = 0; i < limit; ++i) {
        if (arr[i] == elem) {
            return true;
        }
    }
    return false;
}

struct OneVote {
    string letter;
    int percentage;
};

/*
 * ModifiedBubbleSort() function sorts an array of letters in alphabetical row.
 */
void ModifiedBubbleSort (const int size, OneVote arr[]) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j + 1].letter[0] < arr[j].letter[0]) {
                // Swap values.
                string temp = arr[j + 1].letter;
                arr[j + 1].letter = arr[j].letter;
                arr[j].letter = temp;
            }
        }
    }
}

/*
 * AskPublic() function simulates the "Ask the Audience" lifeline.
 * Displays the public's vote for the correct answer with a given truth probability.
 */
void AskPublic(const Question& thisQuestion, const int questIndex) {
    const int numOfquest = 4;

    OneVote audience[numOfquest];

    int min = 1,
        max = 100,
        prevGenerated[numOfquest],             // To store the indexes of previously generated questions.
        questsRow[numOfquest] = {1, 2, 3, 4};  // To store each permutation of question indexes.

    struct MyAnswer {
        unsigned int num;
        char letter;
    };

    MyAnswer ansA {
            1, 'A'
    };
    MyAnswer ansB {
            2, 'B'
    };
    MyAnswer ansC {
            3, 'C'
    };
    MyAnswer ansD {
            4, 'D'
    };

    // Define which is the correct answer.
    if (thisQuestion.answer == ansA.letter) {
        Initialise(questsRow, ansA.num, ansB.num, ansC.num, ansD.num);
    }
    else {
        if (thisQuestion.answer == ansB.letter) {
            Initialise(questsRow, ansB.num, ansA.num, ansC.num, ansD.num);
        }
        else {
            if (thisQuestion.answer == ansC.letter) {
                Initialise(questsRow, ansC.num, ansA.num, ansB.num, ansD.num);
            }
            else {
                Initialise(questsRow, ansD.num, ansA.num, ansB.num, ansC.num);
            }
        }
    }

    // Initial generation of a random index.
    int randIndex = GenerateQuestionNumber(questIndex, questsRow);
    // Save it.
    prevGenerated[0] = randIndex;

    // Take public's vote percentage for this answer.
    switch (randIndex) {
        case 1:
            audience[0].letter = "A";
            break;
        case 2:
            audience[0].letter = "B";
            break;
        case 3:
            audience[0].letter = "C";
            break;
        case 4:
            audience[0].letter = "D";
            break;
    }
    audience[0].percentage = GenerateRandom(max, min);

    // Repeat the same for the rest three questions.
    for (int i = 1; i < numOfquest; ++i) {
        while (IsIncluded(prevGenerated, i, randIndex)) {
            randIndex = GenerateQuestionNumber(questIndex, questsRow);
        }
        prevGenerated[i] = randIndex;
        switch (randIndex) {
            case 1:
                audience[i].letter = "A";
                break;
            case 2:
                audience[i].letter = "B";
                break;
            case 3:
                audience[i].letter = "C";
                break;
            case 4:
                audience[i].letter = "D";
                break;
        }
        max -= audience[i - 1].percentage;
        audience[i].percentage = GenerateRandom(max, min);
    }

    // Calculate last vote's percentage in order to have percentage sum of 100%.
    audience[numOfquest - 1].percentage = 100 - audience[0].percentage - audience[1].percentage - audience[2].percentage;
    ModifiedBubbleSort(numOfquest, audience);

    // Display public's vote.
    Print(CENTER, audience[0].letter + " - " + to_string(audience[0].percentage) + "%\n", LINE);
    Print(CENTER, audience[1].letter + " - " + to_string(audience[1].percentage) + "%\n", LINE);
    Print(CENTER, audience[2].letter + " - " + to_string(audience[2].percentage) + "%\n", LINE);
    Print(CENTER, audience[3].letter + " - " + to_string(audience[3].percentage) + "%\n", LINE);
    cout << '\n';
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

    unsigned int randomNum = GenerateRandom(ansA.num, ansD.num);

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
    Print(CENTER, "Hi, I suppose the correct answer is ", LINE);
    cout << guess.letter << ".\n";
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
    Print(CENTER, "Would you like to use any lifelines?\n", LINE);
    Print(CENTER, "Y - Yes/No - N: ", LINE);

    // Process user's choice.
    string yes_no;
    cin >> yes_no;

    // Handle invalid input.
    while (!(yes_no == "Y" and yes_no == "y" and yes_no == "N" and yes_no == "n")) {
        cin.ignore();
        cin.clear();
        cin >> yes_no;
    }

    cout << '\n';
    if (yes_no == "N" or yes_no == "n") {
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
        cout << '\n';
        Print(CENTER, "Invalid choice of lifeline!\n", LINE);
        Print(CENTER, "Please, enter an available number of a lifeline: ", LINE);
        cin >> choice;
    }

    cout << '\n';
    if (choice == "1") {                      // Check if this is the lifeline of choice.
        fiftyFifty = true;                    // Set lifeline to already used.
        FiftyFifty(temp, questNum);           // Use lifeline.
        return;
    }
    if (choice == "2") {                      // Check if this is the lifeline of choice.
        askPublic = true;                     // Set lifeline to already used.
        AskPublic(temp, questNum);            // Use lifeline.
        return;
    }
    if (choice == "3") {                      // Check if this is the lifeline of choice.
        friendCall = true;                    // Set lifeline to already used.
        FriendCall();                         // Use lifeline.
        return;
    }
}