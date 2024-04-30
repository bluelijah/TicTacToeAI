#include <chrono>
#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread> // For sleep_for function
#include <vector>
#include "print.h"
#include "GameState.h"
#include "board.h"
#include "tictactoe.h"


using namespace std;
using namespace std::chrono;

int main() {
    int start = 0;
    string playerinput;
    TicTacToe game;
    TicTacToeBot game1;

    while (true) {
        switch (start) {
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
                if (playerinput == "") {
                    start = 0;
                }
                else {
                    while (playerinput != "") {
                        system("clear");
                        cout << "Invalid. Press Enter to continue: ";
                        getline(cin, playerinput);
                        if (playerinput == "") {
                            start = 0;
                            break;
                        }
                    }
                }
                break;

            case 2: {
                system("clear");
                int boardSize;
                cout << "Enter the size of the board (3, 4, or 5): ";
                cin >> boardSize;
                if (boardSize < 3 || boardSize > 5) {
                    invalid();
                    break;
                }

                TicTacToe game(boardSize);
                auto start_time = steady_clock::now(); // Start timing
                game.play();
                auto end_time = steady_clock::now(); // End timing
                auto duration = duration_cast<seconds>(end_time - start_time); // Calculate duration
                
                // Flush output stream before introducing delay
                cout << flush;

                // Introduce a delay before printing the time
                this_thread::sleep_for(chrono::milliseconds(500)); // 500 milliseconds

                cout << "Player's turn took: " << duration.count() << " seconds." << endl;

                cout << "Press Enter to continue to the menu: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                getline(cin, playerinput);
                if (playerinput == "") {
                    start = 0;
                }
                else {
                    while (playerinput != "") {
                        system("clear");
                        cout << "Invalid. Press Enter to continue to the menu: ";
                        getline(cin, playerinput);
                        if (playerinput == "") {
                            start = 0;
                            break;
                        }
                    }
                }
                break;
            }

            case 3: {
                system("clear");
                int boardSize;
                cout << "Enter the size of the board (3, 4, or 5): ";
                cin >> boardSize;
                if (boardSize < 3 || boardSize > 5) {
                    invalid();
                    break;
                }

                TicTacToeBotEasy game(boardSize);
                auto start_time = steady_clock::now(); // Start timing
                game.play();
                auto end_time = steady_clock::now(); // End timing
                auto duration = duration_cast<seconds>(end_time - start_time); // Calculate duration
                
                // Flush output stream before introducing delay
                cout << flush;

                // Introduce a delay before printing the time
                this_thread::sleep_for(chrono::milliseconds(500)); // 500 milliseconds

                cout << "Bot's turn took: " << duration.count() << " seconds." << endl;

                cout << "Press Enter to continue to the menu: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, playerinput);
                if (playerinput == "") {
                    start = 0;
                }
                else {
                    while (playerinput != "") {
                        system("clear");
                        cout << "Invalid. Press Enter to continue to the menu: ";
                        getline(cin, playerinput);
                        if (playerinput == "") {
                            start = 0;
                            break;
                        }
                    }
                }
                break;
            }

            case 4: {
                system("clear");
                TicTacToeBot game1;
                auto start_time = steady_clock::now(); // Start timing
                game1.play();
                auto end_time = steady_clock::now(); // End timing
                auto duration = duration_cast<seconds>(end_time - start_time); // Calculate duration
                
                // Flush output stream before introducing delay
                cout << flush;

                // Introduce a delay before printing the time
                this_thread::sleep_for(chrono::milliseconds(500)); // 500 milliseconds

                cout << "Bot's turn took: " << duration.count() << " seconds." << endl;

                cout << "Press Enter to continue to the menu: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, playerinput);
                if (playerinput == "") {
                    start = 0;
                }
                else {
                    while (playerinput != "") {
                        system("clear");
                        cout << "Invalid. Press Enter to continue to the menu: ";
                        getline(cin, playerinput);
                        if (playerinput == "") {
                            start = 0;
                            break;
                        }
                    }
                }
                break;
            }

            case 5:
                system("clear");
                printGameOver();
                return 0;
        }
    }
}