#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "board.h"

struct TicTacToe{

    Board board;

    bool player1;
    bool done;

    TicTacToe(){
        player1 = true;
        done = false;
    }

    TicTacToe(int size) : board(size), player1(true), done(false){}
    
    void play(){
        while(!done) {
            system("clear");
            std::cout << board;

            if (player1) {
                bool success = false;
                while (!success) {
                    int x, y;
                    std::cout << "Player 1: ";
                    std::cin >> x >> y;
                    success = board.update(x, y, PLAYER1);
                }
            } else {
                bool success = false;
                while (!success) {
                    int x, y;
                    std::cout << "Player 2: ";
                    std::cin >> x >> y;
                    success = board.update(x, y, PLAYER2);
                }
            }
            player1 = !player1;

            if (board.isWinner(PLAYER1)) {
                system("clear");
                std::cout << board;
                std::cout << "Player 1 wins!!!" << std::endl;
                done = true;
            } else if (board.isWinner(PLAYER2)) {
                system("clear");
                std::cout << board;
                std::cout << "Player 2 wins!!!" << std::endl;
                done = true;
            }
            else if (board.full()){
                system("clear");
                std::cout << board;
                std::cout << "It's a tie" << std::endl;
                done = true;
            }
        }
    }

};

#endif