#ifndef PRINT_H
#define PRINT_H

#include <iostream>
using namespace std;


void printMenu(){
        std::cout<< "|=======================================|" << '\n';
        std::cout<< "|        Welcome to Tic Tac Toe         |" << '\n';
        std::cout<< "|=======================================|" << '\n';
        std::cout<< "|                                       |" << '\n';
        std::cout<< "|      Please Choose an option 1-5      |" << '\n';
        std::cout<< "|     +===========================+     |" << '\n';
        std::cout<< "|                                       |" << '\n';
        std::cout<< "| 1) How to Play                        |" << '\n';
        std::cout<< "|                                       |" << '\n';
        std::cout<< "| 2) Play Game P:1 VS P:2               |" << '\n';
        std::cout<< "|                                       |" << '\n';
        std::cout<< "| 3) Play Game P:1 VS Beginner AI       |" << '\n';
        std::cout<< "|                                       |" << '\n';
        std::cout<< "| 4) Play Game P:1 VS Advance AI        |" << '\n';
        std::cout<< "|                                       |" << '\n';
        std::cout<< "| 5) Game End - come back soon :}       |" << '\n';
        std::cout<< "|                                       |" << '\n';
        std::cout<< "|=======================================|" << '\n';
        std::cout<< "                                         " << '\n';
        cout << "Your Choice Here: ";

}
void printRules(){
        cout<< "|=======================================|" << '\n';
        cout<< "|       The Rules of Tic Tac Toe        |" << '\n';
        cout<< "|=======================================|" << '\n';
        cout<< "| 1) You will always go first           |" << '\n';
        cout<< "|                                       |" << '\n';
        cout<< "| 2) Enter your row, then column        |" << '\n';
        cout<< "|                                       |" << '\n';
        cout<< "| 3) Try to line up 3 in a row          |" << '\n';
        cout<< "|                                       |" << '\n';
        cout<< "| 4) Get 3 in a row, you win!           |" << '\n';
        cout<< "|                                       |" << '\n';
        cout<< "| 5) Let your opponent get 3 in a row,  |" << '\n';
        cout<< "| You Lose!                             |" << '\n';
        cout<< "|=======================================|" << '\n';
        cout<< "                                         " << '\n';
        cout<< "Press Enter to continue: ";
}

void printGameOver(){
        cout<< "|=======================================|" << '\n';
        cout<< "|+++++++++++++++++++++++++++++++++++++++|" << '\n';
        cout<< "|              GAME OVER                |" << '\n';
        cout<< "|+++++++++++++++++++++++++++++++++++++++|" << '\n';
        cout<< "|=======================================|" << '\n';
}
#endif