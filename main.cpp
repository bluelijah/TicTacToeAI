#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int start = 0;
    if (start == 0){
        cout << "------------------------\n";
        cout << "| WELCOME TO TICTACTOE |\n";
        cout << "------------------------\n";
        cout << "|         TYPE:        |\n";
        cout << "| 1) For the Rules     |\n";
        cout << "| 2) To do X           |\n";
        cout << "| 3) To do X           |\n";
        cout << "| 4) To do X           |\n";
        cout << "| 5) To do X           |\n";
        cout << "------------------------\n";
        string playerinput;
        getline(cin,playerinput);
        start = stoi(playerinput);
    }
    if(start == 1){
        system("clear");
    }

    return 0;
}