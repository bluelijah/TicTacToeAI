#include <iostream>
//#include "GameState.h"
#include "tictactoe.h"
#include "board.h"
using namespace std;

int main(){
    TicTacToe game;

    game.play();

    return 0;
    // GameState game;

    // game.play(0, 0);
    // game.play(1, 1);

    //do{
        cout<< "|=======================================|" << endl;
        cout<< "|        Welcome to Tic Tac Toe         |" << endl;
        cout<< "|=======================================|" << endl;
        cout<< "|      Please Choose an option 1-5      |" << endl;
        cout<< "|                                       |" << endl;
        cout<< "| 1) How to Play                        |" << endl;
        cout<< "|                                       |" << endl;
        cout<< "| 2) Play Game P:1 VS P:2               |" << endl;
        cout<< "|                                       |" << endl;
        cout<< "| 3) Play Game P:1 VS Beginner AI       |" << endl;
        cout<< "|                                       |" << endl;
        cout<< "| 4) Play Game P:1 VS Advance AI        |" << endl;
        cout<< "|                                       |" << endl;
        cout<< "| 5) Game End - come back soon 🙂       |" << endl;
        cout<< "|                                       |" << endl;
        cout<< "|=======================================|" << endl;
    //}
    //while(opt == 2){}
    //while(opt == 1){}
    //while(opt == 3){}
    //while(opt == 4){}
    //while(opt == 5){
        //cout<< "|=======================================|" << endl;
        //cout<< "|+++++++++++++++++++++++++++++++++++++++|" << endl;
        //cout<< "|              GAME OVER                |" << endl;
        //cout<< "|+++++++++++++++++++++++++++++++++++++++|" << endl;
        //cout<< "|=======================================|" << endl;




}



//     int start = 0;
//     if (start == 0){
//         cout << "------------------------\n";
//         cout << "| WELCOME TO TICTACTOE |\n";
//         cout << "------------------------\n";
//         cout << "|         TYPE:        |\n";
//         cout << "| 1) For the Rules     |\n";
//         cout << "| 2) To do X           |\n";
//         cout << "| 3) To do X           |\n";
//         cout << "| 4) To do X           |\n";
//         cout << "| 5) To do X           |\n";
//         cout << "------------------------\n";
//         string playerinput;
//         getline(cin,playerinput);
//         start = stoi(playerinput);
//     }
//     if(start == 1){
//         system("clear");
//     }

//     return 0;
// }