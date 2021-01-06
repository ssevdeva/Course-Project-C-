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

using namespace std;

const int INDIAN_RED = 203,
          SPRING_GREEN = 121;

const int LINE = 80;

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
    const int LETTERCASE = 'a' - 'A';

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

void MainMenu();

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
    myPath = "Resources/" + myPath;

    ifstream MyFile;
    MyFile.open(myPath, ios::in);
    if (!MyFile.is_open()) {
        return false;
    }

    ofstream MyWorkFile("Resources/workFile.txt");

    getline(MyFile, line);
    MyWorkFile << line << endl;
    while ((line != to_string(level) + '.') and !MyFile.eof()) {
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

    char oldName[] = "Resources/workFile.txt";
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
    Print(CENTER, "Press ENTER continue...", LINE);
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
 * AddQuestion() adds a new question in a category.
 */
void AddQuestion() {
    int topic;
    int level;
    string question,
           ansA,
           ansB,
           ansC,
           ansD;
    char answer;

    cout << termcolor::color<SPRING_GREEN>;
    Print(CENTER, "Choose a category for the question", LINE);
    cout << "\n\n";
    Print(CENTER, "1. Geography  2. History  3. Literature  4. Physics  5. Politics  \n\n", LINE);
    Print(CENTER, "Enter: ", LINE);

    cin >> topic;
    while (topic < 1 or topic > 5 or cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << termcolor::color<INDIAN_RED> << '\n';
        Print(CENTER, "Invalid choice!\n", LINE);
        Print(CENTER, "Please, enter valid selection: ", LINE);
        cin >> topic;
    }
    cout << '\n';

    char t;
    string sourceFile;

    switch (topic) {
        case Geography: {
            t = 'g';
            sourceFile = "geography.txt";
        }
            break;
        case History: {
            t = 'h';
            sourceFile = "history.txt";
        }
            break;
        case Literature: {
            t = 'l';
            sourceFile = "literature.txt";
        }
            break;
        case Physics: {
            t = 'p';
            sourceFile = "physics.txt";
        }
            break;
        case Politics: {
            t = 'P';
            sourceFile = "politics.txt";
        }
            break;
        default:
            break;
    }

    cout << termcolor::color<SPRING_GREEN>;
    Print(CENTER, "Choose a level of difficulty (1 - 10): ", LINE);
    cin >> level;
    while (level < 1 or level > 10 or cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << termcolor::color<INDIAN_RED> << '\n';
        Print(CENTER, "Invalid choice!\n", LINE);
        Print(CENTER, "Please, enter valid selection: ", LINE);
        cin >> level;
    }
    cout << '\n';
    cout << termcolor::color<SPRING_GREEN>;
    Print(CENTER, "Please, enter your question: \n", LINE);
    GetWholeLine(question);

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

    cout << "Correct answer: ";
    cin >> answer;

    while (answer != 'A' and answer != 'B' and answer != 'C' and answer != 'D') {
        cin.clear();
        cin.ignore();
        cout << termcolor::color<INDIAN_RED> << '\n';
        Print(CENTER, "Invalid choice!\n", LINE);
        Print(CENTER, "Please, enter valid selection: ", LINE);
        cin >> answer;
    }

    switch (answer) {
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
    question = question + "\n" + ansA + "\n" + ansB + "\n" + ansC + "\n" + ansD + "\n";
    Border();

    string addText = GenerateID(t, level) + "\n" + question;
    if (AddContent(sourceFile, addText, level)) {
        cout << termcolor::color<SPRING_GREEN> << '\n';
        Print(CENTER, "The question has been successfully added!\n", LINE);
        Redirect();
    }
    else {
        cout << termcolor::color<INDIAN_RED> << "Trouble adding new question!";
        Redirect();
        return;
    }
}

/*
 * ChooseMenuOptn() function displays main menu and gets user's choice.
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
            break;
        case ExitGame:
            break;
    }
}

int main() {
    MainMenu();
    return 0;
}
