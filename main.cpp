#include <iostream>
//#include "GameState.h"
#include "tictactoe.h"
#include "board.h"
#include "print.h"
using namespace std;

int main(){

    int start = 0;
    if(start == 0){
        system("clear");
        printMenu();
        string playerinput;
        getline(cin, playerinput);
        start = 0;
        start = stoi(playerinput);
    }
    if(start == 1){
        system("clear");
        printRules();
        string playerinput;
        getline(cin, playerinput);
        while(playerinput != ""){
            cout << "Press Enter to continue:" << endl;
            getline(cin, playerinput);
            if(playerinput == ""){
                start = 0;
                break;
            }
        }
        
    }
    if(start == 2){
        TicTacToe game;
        game.play();
    }
    if(start == 5){
        system("clear");
        printGameOver();
    }


    return 0;
    // GameState game;

    // game.play(0, 0);
    // game.play(1, 1);
}