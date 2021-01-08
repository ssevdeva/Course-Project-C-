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
#include <string>
#include <cstring>
#include <fstream>

#include "Structs_Constants.h"
#include "TakeQuestionFunc.h"

using namespace std;

/*
 * AddContent() function tries to include myText in MyFile and returns FALSE/TRUE if un/successful
 */
bool AddContent(string& myPath, const string& myText, const int level) {
    string line;

    ifstream MyFile;
    MyFile.open(myPath, ios::in);
    if (!MyFile.is_open()) {
        return false;
    }

    ofstream MyWorkFile(WORK_SRC);

    // This is how levels are written in the source text files.
    string lvl = to_string(level) + '.';

    getline(MyFile, line);
    MyWorkFile << line << endl;
    while (line == lvl and !MyFile.eof()) {
        getline(MyFile, line);
        MyWorkFile << line << endl;
    }

    MyWorkFile << myText << endl;

    while (getline(MyFile, line)) {
        MyWorkFile << line << endl;
    }

    if (!MyFile.eof()) {
        return false;
    }

    MyFile.close();
    MyWorkFile.close();

    char oldName[] = WORK_SRC;
    char newName[myPath.length()];
    strcpy(newName, myPath.c_str());

    if (remove(newName) != 0) {
        return false;
    }
    if (rename(oldName, newName) != 0) {
        return false;
    }
    return true;
}

/*
 * RemoveQuestion() function removes the information for a whole question
 * starting from its ID number (startPoint) from a text file with the path pathName.
 */
bool RemoveQuestion(const string& pathName, const string& startPoint) {
    string line;

    // Check if source file is open.
    ifstream MyFile;
    MyFile.open(pathName, ios::in);
    if (!MyFile.is_open()) {
        return false;
    }

    // Create a new file and copy the questions that need to be kept.
    ofstream MyWorkFile(WORK_SRC);

    getline(MyFile, line);
    while (!(line == startPoint or MyFile.eof())) {
        MyWorkFile << line << endl;
        getline(MyFile, line);
    }

    // When startPoint (the question ID number) is reached, the whole question is skipped.
    if (line == startPoint) {
        for (int cnt = 0; cnt <= 5; ++cnt) {
            getline(MyFile, line);
        }
    }

    // The rest of the questions are copied to MyWorkFile.
    while (getline(MyFile, line)) {
        MyWorkFile << line << endl;
    }

    if (!MyFile.eof()) {
        return false;
    }

    MyFile.close();
    MyWorkFile.close();

    char oldName[] = WORK_SRC;
    char newName[pathName.length()];
    strcpy(newName, pathName.c_str());

    // Remove the file with the question that had to be deleted.
    if (remove(newName) != 0) {
        return false;
    }
    // Rename MyWorkFile so that it has the same name as MyFile.
    // The renamed file stores the questions from MyFile without the one that had to be deleted.
    if (rename(oldName, newName) != 0) {
        return false;
    }
    return true;
}

/*
 * SearchFile() function checks if myText is in the text file with pathName.
 */
bool SearchFile(const string& myText, const string& pathName) {
    string line;

    ifstream MyFile;
    MyFile.open(pathName, ios::in);
    if (!MyFile.is_open()) {
        return false;
    }

    // Read file while myText is not found.
    getline(MyFile, line);
    while ((line != myText) and !MyFile.eof()) {
        getline(MyFile, line);
    }

    // If myText is found, remove the question from the file.
    if (line == myText) {
        MyFile.close();
        if (RemoveQuestion(pathName, myText)) {
            return true;
        }
        return false;
    }
    MyFile.close();
    return false;
}