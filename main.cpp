#include <iostream>
#include "tictactoe.h"
#include "board.h"
#include "print.h"
// #include "easybot.cpp"
// #include "bot.cpp"
#include <iostream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

    int start = 0;
    string playerinput; 
    TicTacToe game;
    while(true){
        switch(start){

            case 0:
                system("clear");
                printMenu();
                // string playerinput;
                getline(cin, playerinput);
                start = stoi(playerinput);
                break;
            
            case 1:
                system("clear");
                printRules();
                getline(cin, playerinput);
                if(playerinput == ""){
                    start = 0;
                } else{
                    while(playerinput != ""){
                        system("clear");
                        cout << "Invalid. Press Enter to continue:" << endl;
                        getline(cin, playerinput);
                        if(playerinput == ""){
                            start = 0;
                            break;
                        }
                    }   
                }
                break;
            
            case 2:
                game.play();
                start = 0;
                break;

            // case 3:
            //     TicTacToeBot bot;
            //     bot.play();
            //     return 0;

            
            case 5:
                system("clear");
                printGameOver();
                return 0;
            
        }
        
        // GameState game;

        // game.play(0, 0);
        // game.play(1, 1);
    }
}