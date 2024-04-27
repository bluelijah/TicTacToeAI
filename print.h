#ifndef PRINT_H
#define PRINT_H

#include <iostream>
using namespace std;

#define BRED "\e[1;31m"
#define BLU "\e[0;34m"
#define GRN "\e[0;32m"
#define RESET "\e[0m"

// void printMenu(){
//         std::cout<< "|=======================================|" << '\n';
//         std::cout<< "|\033[35m        Welcome to Tic Tac Toe         \033[0m|" << '\n';
//         std::cout<< "|=======================================|" << '\n';
//         std::cout<< "|                                       |" << '\n';
//         std::cout<< "|\033[35m      Please Choose an option 1-5      \033[0m|" << '\n';
//         std::cout<< "|     +===========================+     |" << '\n';
//         std::cout<< "|                                       |" << '\n';
//         std::cout<< "|\033[35m 1) How to Play                        \033[0m|" << '\n';
//         std::cout<< "|                                       |" << '\n';
//         std::cout<< "|\033[35m 2) Play Game P:1 VS P:2               \033[0m|" << '\n';
//         std::cout<< "|                                       |" << '\n';
//         std::cout<< "|\033[35m 3) Play Game P:1 VS Beginner AI       \033[0m|" << '\n';
//         std::cout<< "|                                       |" << '\n';
//         std::cout<< "|\033[35m 4) Play Game P:1 VS Advance AI        \033[0m|" << '\n';
//         std::cout<< "|                                       |" << '\n';
//         std::cout<< "|\033[35m 5) Game End - come back soon :}       \033[0m|" << '\n';
//         std::cout<< "|                                       |" << '\n';
//         std::cout<< "|=======================================|" << '\n';
//         std::cout<< "                                         " << '\n';
//         cout << "\033[35mYour Choice Here: \033[0m";

// }

void printMenu(){
        std::cout << BLU << "  ============================" << RESET << '\n';
        std::cout << BLU << "  |  " << RESET << BRED << "Welcome To Tic Tac Toe" << RESET << BLU << "  |" << RESET << '\n';
        std::cout << BLU << "  ============================" << RESET << '\n';
        std::cout << '\n';
        std::cout << BLU << "--------------------------------" << RESET << '\n';
        std::cout << BLU << "|" << RESET << BRED <<" 1. How to play?          "<< RESET << BLU << "    |" << RESET << '\n';
        std::cout << BLU << "--------------------------------" << RESET << '\n';
        std::cout << BLU << "--------------------------------" << RESET << '\n';
        std::cout << BLU << "|" << RESET<< BRED <<" 2. Player vs Player      "<< RESET<< BLU << "    |" << RESET << '\n';
        std::cout << BLU << "--------------------------------" << RESET << '\n';
        std::cout << BLU << "--------------------------------" << RESET << '\n';
        std::cout << BLU << "|" << RESET << BRED << " 3. Player vs Computer (easy)"<< RESET << BLU << " |" << RESET << '\n';
        std::cout << BLU << "--------------------------------" << RESET << '\n';
        std::cout << BLU << "--------------------------------" << RESET << '\n';
        std::cout << BLU << "|" << RESET << BRED << " 4. Player vs Computer (hard)"<< RESET << BLU << " |" << RESET << '\n';
        std::cout << BLU << "--------------------------------" << RESET << '\n';
        std::cout << BLU << "--------------------------------" << RESET << '\n';
        std::cout << BLU << "|" << RESET << BRED << " 5. Exit Game             "<< RESET << BLU << "    |" << RESET << '\n';
        std::cout << BLU << "--------------------------------" << RESET << '\n';
        std::cout << BRED << "Enter your choice here: " << RESET;
}

void printRules() {
        std::cout << BLU << "                                                      +=============+" << RESET << '\n';
        std::cout << BLU << "                                                      |" << RESET << GRN << " HOW TO PLAY " << RESET << BLU << "|" << RESET << '\n';
        std::cout << BLU << "                                                      +=============+" << RESET << '\n';
        std::cout << '\n';
        std::cout << BLU << "+===============================================================================================================+" << RESET << '\n';
        std::cout << BLU << "|" << RESET << GRN << " Your goal is to get three of your X's or O's in a row before your opponent, either horizontally, vertically," << RESET << BLU << "  |" << RESET << '\n';
        std::cout << BLU << "|" << RESET << GRN << "   or diagonally. The game board is represented by a 3x3 grid. Players take turns placing their X or O " << RESET << BLU << "        |" << RESET << '\n';
        std::cout << BLU << "|"<< RESET << GRN << "   marks in empty cells. The first player to achieve a row, column, or diagonal with three of their marks wins!" << RESET << BLU << "|" << RESET << '\n';
        std::cout << BLU << "+===============================================================================================================+" << RESET << '\n';
        std::cout << '\n';
        std::cout << GRN <<  "Here's an example game board:" << RESET << "\n";
        std::cout << '\n';
        std::cout << "   0   1   2\n";
        std::cout << "0  " << BRED << "X" << RESET << " | " << BLU << "O" << RESET << " | " << BLU << "O" << RESET << "\n";
        std::cout << "  -----------\n";
        std::cout << "1  " << BRED << "X" << RESET << " | " << BRED << "X" << RESET << " | " << BRED << "X" << RESET << "\n";
        std::cout << "  -----------\n";
        std::cout << "2  " << BRED << "X" << RESET << " | " << BLU << "O" << RESET << " | " << BLU << "O" << RESET << "\n";
        std::cout << '\n';
        std::cout << GRN << "In that game " << RESET << BRED << 'X' << RESET << GRN << " had beaten the " << BLU << "O" << RESET << GRN << " as they achieved three in a row!" << RESET << '\n';
        std::cout << '\n';
        std::cout << "Press Enter to return to the main menu: [ENTER]";
}

void printGameOver(){
        cout<< BLU << "|=======================================|" << RESET << '\n';
        cout<< BLU << "|+++++++++++++++++++++++++++++++++++++++|" << RESET << '\n';
        cout<< BLU << "|"<< RESET << BRED << "              GAME OVER                "<< RESET << BLU << "|" << RESET <<'\n';
        cout<< BLU << "|+++++++++++++++++++++++++++++++++++++++|" << RESET << '\n';
        cout<< BLU << "|=======================================|" << RESET << '\n';
}

void Bye(){
        std::cout << '\n';
        std::cout << BRED << "Thanks for playing!" << RESET << '\n';
}


#endif