
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

    int start = 0;
    string playerinput; 
    TicTacToe game;
    TicTacToeBot game1;
    TicTacToeBotEasy game2;
    while(true){
        switch(start){

            case 0:
                system("clear");
                printMenu();
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
                        cout << "Invalid. Press Enter to continue: ";
                        getline(cin, playerinput);
                        if(playerinput == ""){
                            start = 0;
                            break;
                        }
                    }   
                }
                break;
            
            case 2:
                system("clear");
                game.play();
                cout << "Press Enter to continue to the menu: ";
                cin.ignore();
                getline(cin, playerinput);
                if(playerinput == ""){
                    start = 0;