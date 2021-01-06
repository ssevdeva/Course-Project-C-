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

void Border() {
    string header(LINE, '=');
    cout << termcolor::color<SPRING_GREEN> << header << '\n';
}

void ClearScreen() {
    for (int i = 0; i < 5; ++i) {
        cout << '\n';
    }
}

void MainMenuPrint() {
    Border();
    Print(CENTER, " WHO WANTS TO BE A MILLIONAIRE \n", LINE);
    cout << '\n';
    cout << termcolor::color<SPRING_GREEN>;
    Print(CENTER, "N - New Game\n", LINE);
    Print(CENTER, "A - Add Question\n", LINE);
    Print(CENTER, "M - Modify Question\n", LINE);
    Print(CENTER, "E - Exit\n\n", LINE);
}

void MainMenuOption(Option &choice) {
    const int LETTERCASE = 'a' - 'A';

    int valid = 0;
    char opt;

    while (valid != 1) {
        if (valid < 0) {
            Border();
            ClearScreen();
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

void CategoriesPrint() {
    Border();
    cout << '\n';
    cout << termcolor::color<SPRING_GREEN>;
    Print(CENTER, "1. Geography\n", LINE);
    Print(CENTER, "2. History\n", LINE);
    Print(CENTER, "3. Literature\n", LINE);
    Print(CENTER, "4. Physics\n", LINE);
    Print(CENTER, "5. Politics\n", LINE);
    Print(CENTER, "6. All Categories\n\n", LINE);
}

void CategoriesOption(Category &topic) {
    int valid = 0;
    int opt;

    while (valid != 1) {
        if (valid < 0) {
            Border();
            ClearScreen();
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


int main() {

    Option choice = NewGame;
    MainMenuPrint();
    MainMenuOption(choice);
    ClearScreen();
    Category topic = Geography;
    CategoriesPrint();
    CategoriesOption(topic);

    return 0;
}
