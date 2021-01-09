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
#include <string>

#include "structsNconstants.h"
#include "contentEditors.h"

/*
 * GetLevel() function reads all questions of a single level from ReadFile copies
 * them in WriteFile. Each question receives a next number in front of its ID.
 */
void GetLevel(int lvl, ifstream &ReadFile, ofstream &WriteFile, int &numOfQuest) {
    string line;

    getline(ReadFile, line);  // first question ID

    // Gather questions of lvl. until start of next lvl. questions is not reached.
    while (line != (to_string(lvl + 1) + '.') and !ReadFile.eof()) {
        // Put the number of the question before its ID.
        if (line[0] == '#') {
            ++numOfQuest;
            WriteFile << '\n'; // add a separating line
            WriteFile << to_string(numOfQuest) << endl;
            WriteFile << line << endl;
        }
        else {
            if (!line.empty()) {
                WriteFile << line << endl;
            }
        }
        getline(ReadFile, line);
    }
}

/*
 * GatherAllQuestions() function reads all questions of all categories and saves them in a file
 * with a path called newFilePath. Each question receives a next number in front of its ID.
*/
bool GatherAllQuestions(string &newFilePath, int &easy, int &mild, int &hard) {
    string line;

    // Open all source files in order to get the questions.
    ifstream MyFirstFile;
    MyFirstFile.open(GEO_SRC, ios::in);
    if (!MyFirstFile.is_open()) {
        return false;
    }

    ifstream MySecondFile;
    MySecondFile.open(HIST_SRC, ios::in);
    if (!MySecondFile.is_open()) {
        return false;
    }

    ifstream MyThirdFile;
    MyThirdFile.open(LIT_SRC, ios::in);
    if (!MyThirdFile.is_open()) {
        return false;
    }

    ifstream MyFourthFile;
    MyFourthFile.open(PHYS_SRC, ios::in);
    if (!MyFourthFile.is_open()) {
        return false;
    }

    ifstream MyFifthFile;
    MyFifthFile.open(POL_SRC, ios::in);
    if (!MyFifthFile.is_open()) {
        return false;
    }

    // Create a temporary text file in order to gather info from it during the game.
    newFilePath = WORK_SRC;
    ofstream MyWorkFile(newFilePath);

    MyWorkFile << "EASY" << endl; // Start gathering the easy questions (lvl. 1 - 3).
    getline(MyFirstFile, line);  // 1.
    getline(MySecondFile, line);  // 1.
    getline(MyThirdFile, line);  // 1.
    getline(MyFourthFile, line);  // 1.
    getline(MyFifthFile, line);  // 1.

    for (int i = 1; i <= 3; ++i) {
        GetLevel(i, MyFirstFile, MyWorkFile, easy);
        GetLevel(i, MySecondFile, MyWorkFile, easy);
        GetLevel(i, MyThirdFile, MyWorkFile, easy);
        GetLevel(i, MyFourthFile, MyWorkFile, easy);
        GetLevel(i, MyFifthFile, MyWorkFile, easy);
    }

    MyWorkFile << '\n';
    MyWorkFile << "MILD" << endl; // Start gathering the mild questions (lvl. 4 - 7).
    for (int i = 4; i <= 7; ++i) {
        GetLevel(i, MyFirstFile, MyWorkFile, mild);
        GetLevel(i, MySecondFile, MyWorkFile, mild);
        GetLevel(i, MyThirdFile, MyWorkFile, mild);
        GetLevel(i, MyFourthFile, MyWorkFile, mild);
        GetLevel(i, MyFifthFile, MyWorkFile, mild);
    }

    MyWorkFile << '\n';
    MyWorkFile << "HARD" << endl; // Start gathering the hard questions (lvl. 4 - 7).
    for (int i = 8; i <= 10; ++i) {
        GetLevel(i, MyFirstFile, MyWorkFile, hard);
        GetLevel(i, MySecondFile, MyWorkFile, hard);
        GetLevel(i, MyThirdFile, MyWorkFile, hard);
        GetLevel(i, MyFourthFile, MyWorkFile, hard);
        GetLevel(i, MyFifthFile, MyWorkFile, hard);
    }

    // Check for end of all files.
    if (!MyFirstFile.eof()) {
        return false;
    }
    if (!MySecondFile.eof()) {
        return false;
    }
    if (!MyThirdFile.eof()) {
        return false;
    }
    if (!MyFourthFile.eof()) {
        return false;
    }
    if (!MyFifthFile.eof()) {
        return false;
    }

    // Close all files.
    MyFirstFile.close();
    MySecondFile.close();
    MyThirdFile.close();
    MyFourthFile.close();
    MyFifthFile.close();
    MyWorkFile.close();

    return true;
}

/*
* GatherQuestions() function reads all questions of a category and saves them in a file
 * with a path called newFilePath. Each question receives a next number in front of its ID.
*/
bool GatherQuestions(const Category choice, string &newFilePath, int &easy, int &mild, int &hard) {
    string line;
    string srcFile;

    // Define a source text file according to the user's choice of category.
    switch (choice) {
        case Geography: {
            srcFile = GEO_SRC;
        }
            break;
        case History: {
            srcFile = HIST_SRC;
        }
            break;
        case Literature: {
            srcFile = LIT_SRC;
        }
            break;
        case Physics: {
            srcFile = PHYS_SRC;
        }
            break;
        case Politics: {
            srcFile = POL_SRC;
        }
            break;
        case All: {
            return GatherAllQuestions(newFilePath, easy, mild, hard);
        }
    }

    // Open a category source file in order to get the questions.
    ifstream MyFile;
    MyFile.open(srcFile, ios::in);
    if (!MyFile.is_open()) {
        return false;
    }

    // Create a temporary text file in order to gather info from it during the game.
    newFilePath = WORK_SRC;
    ofstream MyWorkFile(WORK_SRC);



    MyWorkFile << "EASY" << endl; // Start gathering the easy questions (lvl. 1 - 3).
    getline(MyFile, line);  // 1.
    for (int i = 1; i <= LAST_EASY; ++i) {
        GetLevel(i, MyFile, MyWorkFile, easy);
    }

    MyWorkFile << '\n';
    MyWorkFile << "MILD" << endl; // Start gathering the mild questions (lvl. 4 - 7).
    for (int i = 4; i <= LAST_MILD; ++i) {
        GetLevel(i, MyFile, MyWorkFile, mild);
    }

    MyWorkFile << '\n';
    MyWorkFile << "HARD" << endl; // Start gathering the hard questions (lvl. 4 - 7).
    for (int i = 8; i <= LAST_HARD; ++i) {
        GetLevel(i, MyFile, MyWorkFile, hard);
    }
    MyFile.close();
    MyWorkFile.close();

    return true;
}


