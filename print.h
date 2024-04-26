#ifndef PRINT_H
#define PRINT_H

#include <iostream>
using namespace std;




void printMenu(){
        std::cout<< "|=======================================|" << '\n';
        std::cout<< "|\033[35m        Welcome to Tic Tac Toe         \033[0m|" << '\n';
        std::cout<< "|=======================================|" << '\n';
        std::cout<< "|                                       |" << '\n';
        std::cout<< "|\033[35m      Please Choose an option 1-5      \033[0m|" << '\n';
        std::cout<< "|     +===========================+     |" << '\n';
        std::cout<< "|                                       |" << '\n';
        std::cout<< "|\033[35m 1) How to Play                        \033[0m|" << '\n';
        std::cout<< "|                                       |" << '\n';
        std::cout<< "|\033[35m 2) Play Game P:1 VS P:2               \033[0m|" << '\n';
        std::cout<< "|                                       |" << '\n';
        std::cout<< "|\033[35m 3) Play Game P:1 VS Beginner AI       \033[0m|" << '\n';
        std::cout<< "|                                       |" << '\n';
        std::cout<< "|\033[35m 4) Play Game P:1 VS Advance AI        \033[0m|" << '\n';
        std::cout<< "|                                       |" << '\n';
        std::cout<< "|\033[35m 5) Game End - come back soon :}       \033[0m|" << '\n';
        std::cout<< "|                                       |" << '\n';
        std::cout<< "|=======================================|" << '\n';
        std::cout<< "                                         " << '\n';
        cout << "\033[35mYour Choice Here: \033[0m";

}
void printRules(){
        cout<< "|=======================================|" << '\n';
        cout<< "|\033[35m       The Rules of Tic Tac Toe        \033[0m|" << '\n';
        cout<< "|=======================================|" << '\n';
        cout<< "|\033[35m 1) You will always go first           \033[0m|" << '\n';
        cout<< "|                                       |" << '\n';
        cout<< "|\033[35m 2) Enter your row, then column        \033[0m|" << '\n';
        cout<< "|                                       |" << '\n';
        cout<< "|\033[35m 3) Try to line up 3 in a row          \033[0m|" << '\n';
        cout<< "|                                       |" << '\n';
        cout<< "|\033[35m 4) Get 3 in a row, you win!           \033[0m|" << '\n';
        cout<< "|                                       |" << '\n';
        cout<< "|\033[35m 5) Let your opponent get 3 in a row,  \033[0m|" << '\n';
        cout<< "|\033[35m You Lose!                             \033[0m|" << '\n';
        cout<< "|=======================================|" << '\n';
        cout<< "                                         " << '\n';
        cout<< "\033[35mPress Enter to continue: \033[0m";
}

void printGameOver(){
        cout<< "|=======================================|" << '\n';
        cout<< "|+++++++++++++++++++++++++++++++++++++++|" << '\n';
        cout<< "|              GAME OVER                |" << '\n';
        cout<< "|+++++++++++++++++++++++++++++++++++++++|" << '\n';
        cout<< "|=======================================|" << '\n';
}
#endif