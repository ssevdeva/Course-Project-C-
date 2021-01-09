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
#include <cstdlib>
#include <iomanip>

#include "Structs_Constants.h"
#include "BasicFuncs.h"
#include "ContentEditors.h"

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
    int valid = 0;
    char opt;

    while (valid != 1) {
        // Handle invalid input.
        if (valid < 0) {
            Border();
            MainMenuPrint();
            cout << termcolor::color<INDIAN_RED>;
            Print(CENTER, "Invalid choice!\n", LINE);
            Print(CENTER, "Please, enter valid selection: ", LINE);
        }
        else {
            // Ask the user to choose a category.
            cout << termcolor::color<SPRING_GREEN>;
            Print(CENTER, "Enter selection: ", LINE);
        }
        cin >> opt;
        // Define which is the user's choice.
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
        // Handle invalid input.
        if (valid < 0) {
            Border();
            CategoriesPrint();
            cout << termcolor::color<INDIAN_RED>;
            Print(CENTER, "Invalid choice!\n", LINE);
            Print(CENTER, "Please, enter valid selection: ", LINE);
        }
        else {
            // Ask the user to choose a category.
            cout << termcolor::color<SPRING_GREEN>;
            Print(CENTER, "Enter selection: ", LINE);
        }
        // Define which is the chosen category.
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
}

/*
 * ChooseCategory() function displays all categories and gets user's choice of topic.
 */
void ChooseCategory(Category &topic) {
    CategoriesPrint();
    CategoriesOption(topic);
}

/*
 * Redirect() function returns the user to the main menu.
 */
void Redirect() {
    Print(CENTER, "Press ENTER to continue...\n", LINE);
    cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    MainMenu();  // return to the main menu
}

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

bool IsElement(const int elmnt, const int elemsArr[QUESTIONS_IN_GAME], const int questNum) {
    int begin = 0,
        end = 0;

    if (questNum <= FIRST_STAGE) {
        begin = 0;
        end = questNum - 1;
    }

    if (questNum > FIRST_STAGE and questNum <= SECOND_STAGE) {
        begin = FIRST_STAGE;
        end = questNum - 1;
    }

    if (questNum > SECOND_STAGE) {
        begin = SECOND_STAGE;
        end = LAST_STAGE;
    }

    for (int i = begin; i < end; ++i) {
        if (elmnt == elemsArr[i]) {
            return true;
        }
    }
    return false;
}

bool ReadQuestion(const string &srcFile, Question &temp, int questNum, const string &complexity,
                  const int questsAvailable, int (&asked)[QUESTIONS_IN_GAME]) {

    string line;


    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(1, questsAvailable);

    int thisQuestion = distrib(gen);
    while (IsElement(thisQuestion, asked, questNum)) {
        thisQuestion = distrib(gen);
    }
    asked[questNum - 1] = thisQuestion;

    ifstream ReadFile;
    ReadFile.open(srcFile, ios::in);
    if (!ReadFile.is_open()) {
        return false;
    }

    getline(ReadFile, line);
    while (!(line == complexity or ReadFile.eof())) {
        getline(ReadFile, line);
    }

    if (line == complexity) {
        while (line != to_string(thisQuestion)) {
            getline(ReadFile, line);
        }
    }

    if (line == to_string(thisQuestion)) {
        getline(ReadFile, line); // ID number
        temp.questText = "";
        getline(ReadFile, line);
        while (!((line[0] == 'A' and line[1] == ')') or line[0] == '*')) {
            temp.questText += line;
            getline(ReadFile, line);
        }
        if (line[0] == '*') {
            temp.answer = 'A';
            temp.ansA = line.substr(1);
        }
        else {
            temp.ansA = line;
        }
        getline(ReadFile, line);
        if (line[0] == '*') {
            temp.answer = 'B';
            temp.ansB = line.substr(1);
        }
        else {
            temp.ansB = line;
        }
        getline(ReadFile, line);
        if (line[0] == '*') {
            temp.answer = 'C';
            temp.ansC = line.substr(1);
        }
        else {
            temp.ansC = line;
        }
        getline(ReadFile, line);
        if (line[0] == '*') {
            temp.answer = 'D';
            temp.ansD = line.substr(1);
        }
        else {
            temp.ansD = line;
        }
        ReadFile.close();
        return true;
    }
    return false;
}

void PrintQuestion(const int num, const Question& temp, const bool ansA,
                   const bool ansB, const bool ansC, const bool ansD) {
    Border();
    cout << "Question " + to_string(num) << "\n";
    cout << termcolor::color<CHARTEUSE>;
    if (temp.questText.length() > LINE) {
        cout << temp.questText.substr(0, LINE - 1) << endl;
        cout << temp.questText.substr(LINE - 1, temp.questText.length() - 1) << "\n\n";
    } else {
        cout << temp.questText << "\n\n";
    }
    if ((temp.ansA.length() + temp.ansC.length() >= LINE) or (temp.ansB.length() + temp.ansD.length() >= LINE)) {
        if (ansA) {
            cout << temp.ansA << "\n";
        }
        if (ansB) {
            cout << temp.ansA << "\n";
        }
        if (ansC) {
            cout << temp.ansA << "\n";
        }
        if (ansD) {
            cout << temp.ansA << "\n";
        }
    }
    else {
        if (ansA) {
            cout << temp.ansA;
        }
        for (int i = 0; i < (LINE - temp.ansA.length() - temp.ansC.length()); ++i) {
            cout << ' ';
        }
        if (ansC) {
            cout << temp.ansC << "\n\n";
        }
        if (ansB) {
            cout << temp.ansB;
        }
        for (int i = 0; i < (LINE - temp.ansB.length() - temp.ansD.length()); ++i) {
            cout << ' ';
        }
        if (ansD) {
            cout << temp.ansD << "\n\n";
        }
    }
}

/// жокери!!!


bool TakeAnswer(const Question& temp, const int questNum, int &moneyGained) {
    char ans;

    Print(CENTER, "Answer : ", LINE);
    cin >> ans;
    if (ans == temp.answer or ans == temp.answer + LETTERCASE) {

        if (questNum > STAGE1) {
            if ((questNum > STAGE1 + 1 and questNum <= STAGE2) or (questNum > STAGE2 + 1 and questNum <= STAGE3)) {
                moneyGained *= 2;
            } else
                switch (questNum) {
                    case STAGE1 + 1:
                        moneyGained = FORTH_PRIZE;
                        break;
                    case STAGE2 + 1:
                        moneyGained = TWELFTH_PRIZE;
                        break;
                    case STAGE3 + 1:
                        moneyGained = THE_GRAND_MILLION;
                        break;
                    default :
                        break;
                }

        } else {
            moneyGained += INITIAL_PRIZE;
        }
        cout << '\n';
        Print(CENTER, "CONGRATULATIONS!\n", LINE);

        if (questNum != LAST_STAGE) {
            Print(CENTER, ("You reached a prize of " + to_string(moneyGained) + "$."), LINE);
            cout << '\n';
            Print(CENTER, "Press ENTER to continue...\n", LINE);
            cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        }
        else {
            Print(CENTER, "YOU WON THE GRAND 1, 000, 000$.\n", LINE);
        }
        return true;
    }

    cout << termcolor::color<INDIAN_RED>;
    Print(CENTER, "Sorry, the correct answer is ", LINE);
    cout << setw(LINE / 2) << temp.answer << endl;
    cout << termcolor::color<CHARTEUSE>;
    if (questNum <= STAGE1 + 1) {
        moneyGained = 0;
    }
    else {
        if (questNum > STAGE1 + 1 and questNum <= STAGE2 + 1) {
            moneyGained = FORTH_PRIZE;
        }
        else {
            moneyGained = TWELFTH_PRIZE;
        }
    }
    Print(CENTER, ("You won a prize of " + to_string(moneyGained) + "$."), LINE);
    return false;
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
        Question currentQuestion;
        bool isCorrect = true;
        int questNum;
        int askedQuestions[QUESTIONS_IN_GAME];
        int prize = 0;

        for (questNum = 1; (questNum <= FIRST_STAGE and isCorrect); ++questNum) {
            if (ReadQuestion(newFile, currentQuestion, questNum, "EASY", easy, askedQuestions)) {
                PrintQuestion(questNum, currentQuestion, true,true,true,true);
                if (!TakeAnswer(currentQuestion, questNum, prize)) {
                    isCorrect = false;
                }
                // викаш жокерите
                // продължаваш
            }
        }
        for (questNum = 6; (questNum <= SECOND_STAGE and isCorrect); ++questNum) {
            if (ReadQuestion(newFile, currentQuestion, questNum, "MILD", mild, askedQuestions)) {
                PrintQuestion(questNum, currentQuestion, true,true,true,true);
                if (!TakeAnswer(currentQuestion, questNum, prize)) {
                    isCorrect = false;
                }
            }
        }
        for (questNum = 11; (questNum <= LAST_STAGE and isCorrect); ++questNum) {
            if (ReadQuestion(newFile, currentQuestion, questNum, "HARD", hard, askedQuestions)) {
                PrintQuestion(questNum, currentQuestion, true,true,true,true);
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
 * Substitute() function gets the info for the question with a number idNum
 * that needs to be modified and adds it to the corresponding source file.
 */
void Substitute(const string &idNum) {
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