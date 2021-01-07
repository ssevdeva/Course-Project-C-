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
#include <cstdio>
#include <cstring>
#include <random>
#include <cstdlib>

using namespace std;

#define geoSrc "Resources/geography.txt"
#define histSrc "Resources/history.txt"
#define litSrc "Resources/literature.txt"
#define physSrc "Resources/physics.txt"
#define polSrc "Resources/politics.txt"
#define workSrc "Resources/workFile.txt"


const int INDIAN_RED = 203,
          SPRING_GREEN = 121,
          LINE = 80;

enum Option {
    NewGame = 'N', AddQ = 'A', ModifyQ = 'M', ExitGame = 'E'
};
enum Category {
    Geography = 1, History, Literature, Physics, Politics, All
};
enum Position {
    LEFT, CENTER, RIGHT
};

/*
 * Print() function prints aligned string s in the console.
 */
void Print(const Position pos, const string &s, const int linelength) {
    unsigned long spaces = 0;
    switch (pos) {
        case CENTER: {
            spaces = (linelength - s.size()) / 2;
        }
            break;
        case RIGHT: {
            spaces = linelength - s.size();
        }
            break;
        case LEFT:
            break;
    }
    if (spaces > 0) cout << string(spaces, ' ');
    cout << s;
}

/*
 * Border() function creates a border-like display in the console.
 */
void Border() {
    string header(LINE, '=');
    cout << termcolor::color<SPRING_GREEN> << header << '\n';
}

/*
 * TitleBar() function creates a title header display in the console.
 */
void TitleBar() {
    string s = " WHO WANTS TO BE A MILLIONAIRE ";
    string header(LINE / 2 - s.length() / 2, '=');
    cout << termcolor::color<SPRING_GREEN> << header;
    cout << s;
    cout << header << '\n';
}

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
 * AddContent() function tries to include myText in MyFile and returns FALSE/TRUE if un/successful
 */
bool AddContent(string& myPath, const string& myText, const int level) {
    string line;

    ifstream MyFile;
    MyFile.open(myPath, ios::in);
    if (!MyFile.is_open()) {
        return false;
    }

    ofstream MyWorkFile(workSrc);

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

    char oldName[] = workSrc;
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
 * GenerateID() function generates an ID code for each question.
 */
string GenerateID(const char& topic, const int lvl) {
    std::random_device dev;
    std::mt19937 engine(dev());
    return ('#' + to_string(lvl) + topic + to_string(dev()));
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
 * GetWholeLine() function reads from the console and saves the input with its whitespaces in str.
 */
void GetWholeLine(string& str) {
    char input[LINE];
    cin >> str;
    cin.getline(input, LINE);
    for (int i = 0; input[i] != '\0'; ++i) {
        str +=input[i];
    }
}

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
            sourceFile = geoSrc;
        }
            break;
        case History: {
            topicSmbl = 'h';
            sourceFile = histSrc;
        }
            break;
        case Literature: {
            topicSmbl = 'l';
            sourceFile = litSrc;
        }
            break;
        case Physics: {
            topicSmbl = 'p';
            sourceFile = physSrc;
        }
            break;
        case Politics: {
            topicSmbl = 'P';
            sourceFile = polSrc;
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
    GetWholeLine(question);

    // Enter optional answers for the question.
    cout << termcolor::color<SPRING_GREEN>;
    Print(CENTER, "Please, enter the answers: \n", LINE);
    cout << "A) ";
    GetWholeLine(ansA);
    ansA = "A) " + ansA;
    cout << "B) ";
    GetWholeLine(ansB);
    ansB = "B) " + ansB;
    cout << "C) ";
    GetWholeLine(ansC);
    ansC = "C) " + ansC;
    cout << "D) ";
    GetWholeLine(ansD);
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
    ofstream MyWorkFile(workSrc);

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

    char oldName[] = workSrc;
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
    if (SearchFile(idNum, geoSrc)) {
        Substitute(idNum);                      // start modification
    }
    if (SearchFile(idNum, histSrc)) {
        Substitute(idNum);                      // start modification
    }
    if (SearchFile(idNum, litSrc)) {
        Substitute(idNum);                      // start modification
    }
    if (SearchFile(idNum, physSrc)) {
        Substitute(idNum);                      // start modification
    }
    if (SearchFile(idNum, polSrc)) {
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
