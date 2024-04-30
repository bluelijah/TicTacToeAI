#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <iostream>
#include <iostream>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>

struct Vec{
    int x;
    int y;

    Vec(){
        x = 0;
        y = 0;
    }

    Vec(int x, int y){
        this->x = x;
        this->y = y;
    }

    void set(int x, int y){
        this->x = x;
        this->y = y;
    }
};

std::ostream& operator<<(std::ostream& os, const Vec& v){
    os << "(" << v.x << ", " << v.y << ")";

    return os;
}

struct GameState;
std::ostream& operator<<(std::ostream& os, const GameState& state);

struct GameState{
    int** grid;
    bool currentTurn;
    int size;
    int turnCount;

    bool done;
    Vec lastMove;

    GameState(){
        size = 3;
        currentTurn = 0;
        turnCount = 0;
        done = false;

        lastMove.set(-1, -1);

        grid = new int*[size];

        for (int i = 0; i < size; i++){
            grid[i] = new int[size];
            for (int j = 0; j < size; j++){
                grid[i][j] = -1;
            }
        }
    }

    GameState(int size){
        this->size = size;
        currentTurn = 0;
        turnCount = 0;
        done = false;

        lastMove.set(-1, -1);

        grid = new int*[size];

        for (int i = 0; i < size; i++){
            grid[i] = new int[size];
            for (int j = 0; j < size; j++){
                grid[i][j] = -1;
            }
        }
    }

    GameState(const GameState& other){
        size = other.size;
        currentTurn = other.currentTurn;
        turnCount = other.turnCount;
        done = other.done;
        lastMove = other.lastMove;

        grid = new int*[size];

        for (int i = 0; i < size; i++){
            grid[i] = new int[size];
            for (int j = 0; j < size; j++){
                grid[i][j] = other.grid[i][j];
            }
        }
    }

    bool operator==(const GameState& other){
        bool sizeMatch = size == other.size;
        bool currentTurnMatch = currentTurn == other.currentTurn;
        bool turnCountMatch = turnCount == other.turnCount;
        bool doneMatch = done == other.done;
        bool lastMoveMatch = lastMove.x == other.lastMove.x && lastMove.y == other.lastMove.y;
        if (sizeMatch && currentTurnMatch && turnCountMatch && doneMatch && lastMoveMatch){
            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    if (grid[i][j] != other.grid[i][j]){
                        return false;
                    }
                }
            }
            
            return true;
        }
        else{
            return false;
        }
    }

    GameState& operator=(const GameState& other){
        currentTurn = other.currentTurn;
        turnCount = other.turnCount;
        done = other.done;
        lastMove = other.lastMove;

        if (size == other.size){
            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    grid[i][j] = other.grid[i][j];
                }
            }
        }
        else{
            
            for (int i = 0; i < size; i++){
                delete[] grid[i];
            }
            delete[] grid;

            size = other.size;

            grid = new int*[size];

            for (int i = 0; i < size; i++){
                grid[i] = new int[size];
                for (int j = 0; j < size; j++){
                    grid[i][j] = other.grid[i][j];
                }
            }
        }

        return *this;
    }

    bool hasWon(int player){
        for (int i = 0; i < size; i++){
            int count = 0;
            for (int j = 0; j < size; j++){
                if (grid[i][j] == player){
                    count++;
                }
            }
            if (count == size){
                return true;
            }
        }
        for (int i = 0; i < size; i++){
            int count = 0;
            for (int j = 0; j < size; j++){
                if (grid[j][i] == player){
                    count++;
                }
            }
            if (count == size){
                return true;
            }
        }
        int mainDiagCount = 0;
        for (int i = 0; i < size; i++){
            if (grid[i][i] == player){
                mainDiagCount++;
            }
        }
        if (mainDiagCount == size){
            return true;
        }

        int secondaryDiagCount = 0;
        for (int i = 0; i < size; i++){
            if (grid[i][size-1-i] == player){
                secondaryDiagCount++;
            }
        }
        if (secondaryDiagCount == size){
            return true;
        }
        

        return false;
    }

    bool play(int x, int y){
        if (grid[x][y] != -1){
            return false;
        }

        grid[x][y] = currentTurn;
        currentTurn = !currentTurn;
        turnCount++;
        lastMove.set(x, y);

        if (turnCount == size * size){
            done = true;
        }
        else if (hasWon(0) || hasWon(1)){
            done = true;
        }

        return true;
    }

    ~GameState(){
        for (int i = 0; i < size; i++){
            delete[] grid[i];
        }
        delete[] grid;
    }
};

std::ostream& operator<<(std::ostream& os, const GameState& state){
    os << "   ";
    for (int j = 0; j < state.size; j++){
        os << " " << j << "  ";
    }
    os << std::endl;
    os << "   ";
    for (int j = 0; j < state.size; j++){
        os << "--- ";
    }
    os << std::endl;
    for (int i = 0; i < state.size; i++){
        os << i << " ";
        for (int j = 0; j < state.size; j++){
            char c = ' ';
            if (state.grid[i][j] == 0){
                c = 'X';
            }
            else if (state.grid[i][j] == 1){
                c = 'O';
            }
            os << "| " << c << " ";
            if (j == state.size - 1) os << "|";
        }
        os << std::endl << "   ";
        for (int j = 0; j < state.size; j++){
            os << "--- ";
        }
        os << std::endl;
    }

    return os;
}

class TicTacToeBot {
private:
    GameState game;

public:
    TicTacToeBot() : game(3) {}

    void play() 
    {
        std::cout << "Welcome to Tic Tac Toe!\n";
        std::cout << "You are X, and the bot is O.\n";
        std::cout << "Enter row and column numbers to make your move.\n";
        std::cout << game;

        while (!game.done) 
        {
            int x, y;
            std::cout << "Your move (row column): ";
            std::cin >> x >> y;

            if (x < 0 || x >= game.size || y < 0 || y >= game.size || !game.play(x, y)) 
            {
                std::cout << "Invalid move! Try again.\n";
                continue;
            }

            std::cout << game;

            if (game.done) 
            {
                if (game.hasWon(0)) 
                {
                    std::cout << "Congratulations! You won!\n";
                } else if (game.hasWon(1)) 
                {
                    std::cout << "The bot won!\n";
                } else 
                {
                    std::cout << "It's a draw!\n";
                }
                break;
            }

            std::cout << "Bot's move:\n";
            botMove();
            std::cout << game;

            if (game.done) 
            {
                if (game.hasWon(0)) 
                {
                    std::cout << "Congratulations! You won!\n";
                } else if (game.hasWon(1)) 
                {
                    std::cout << "The bot won!\n";
                } else 
                {
                    std::cout << "It's a draw!\n";
                }
                break;
            }
        }
    }

    int minimax(GameState state, int depth, bool isMaximizingPlayer, int alpha, int beta) {
        if (state.done) 
        {
            if (state.hasWon(0)) return -10;
            else if (state.hasWon(1)) return 10;

            else return 0;
        }

        if (isMaximizingPlayer) 
        {
            int maxEval = std::numeric_limits<int>::min();
            for (int i = 0; i < state.size; ++i) {
                for (int j = 0; j < state.size; ++j) 
                {
                    if (state.grid[i][j] == -1) 
                    {
                        GameState nextState = state;
                        nextState.play(i, j);

                        int eval = minimax(nextState, depth + 1, false, alpha, beta);

                        maxEval = std::max(maxEval, eval);
                        alpha = std::max(alpha, eval);

                        if (beta <= alpha)
                            break;
                    }
                }
            }
            return maxEval;
        } else 
        {
            int minEval = std::numeric_limits<int>::max();

            for (int i = 0; i < state.size; ++i) 
            {

                for (int j = 0; j < state.size; ++j) 
                {
                    if (state.grid[i][j] == -1) 
                    {
                        
                        GameState nextState = state;
                        nextState.play(i, j);

                        int eval = minimax(nextState, depth + 1, true, alpha, beta);

                        minEval = std::min(minEval, eval);
                        beta = std::min(beta, eval);

                        if (beta <= alpha)
                            break;
                    }
                }

            }

            return minEval;
        }
    }

    void botMove() 
    {
        int bestVal = std::numeric_limits<int>::min();
        Vec bestMove;

        for (int i = 0; i < game.size; ++i) 
        {
            for (int j = 0; j < game.size; ++j) 
            {
                if (game.grid[i][j] == -1) 
                {
                    GameState nextState = game;
                    nextState.play(i, j);

                    int moveVal = minimax(nextState, 0, false, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

                    if (moveVal > bestVal) 
                    {

                        bestVal = moveVal;
                        bestMove = Vec(i, j);

                    }
                }
            }
        }
        game.play(bestMove.x, bestMove.y);
    }
};

class TicTacToeBotEasy {
private:
    GameState game;

public:
    // Constructor that takes the size of the board as a parameter
    TicTacToeBotEasy(int boardSize) : game(boardSize) {}

    void play() {
        std::cout << "Welcome to Tic Tac Toe!\n";
        std::cout << "You are X, and the bot is O.\n";
        std::cout << "Enter row and column numbers to make your move.\n";
        std::cout << game;

        while (!game.done) {
            int x, y;
            std::cout << "Your move (row column): ";
            std::cin >> x >> y;

            if (x < 0 || x >= game.size || y < 0 || y >= game.size || !game.play(x, y)) {
                std::cout << "Invalid move! Try again.\n";
                continue;
            }

            std::cout << game;

            if (game.done) {
                if (game.hasWon(0)) {
                    std::cout << "Congratulations! You won!\n";
                } else if (game.hasWon(1)) {
                    std::cout << "The bot won!\n";
                } else {
                    std::cout << "It's a draw!\n";
                }
                break;
            }

            std::cout << "Bot's move:\n";
            botMove();
            std::cout << game;

            if (game.done) {
                if (game.hasWon(0)) {
                    std::cout << "Congratulations! You won!\n";
                } else if (game.hasWon(1)) {
                    std::cout << "The bot won!\n";
                } else {
                    std::cout << "It's a draw!\n";
                }
                break;
            }
        }
    }

    // Implementation of botMove remains the same
    void botMove() {
        std::vector<Vec> availableMoves;
        for (int i = 0; i < game.size; ++i) {
            for (int j = 0; j < game.size; ++j) {
                if (game.grid[i][j] == -1) {
                    availableMoves.push_back(Vec(i, j));
                }
            }
        }

        if (availableMoves.empty()) {
            srand(static_cast<unsigned int>(time(0)));
            int randIdx = rand() % (game.size * game.size);
            game.play(randIdx / game.size, randIdx % game.size);
            return;
        }

        for (const auto& move : availableMoves) {
            GameState temp = game;
            temp.play(move.x, move.y);
            if (temp.hasWon(0)) {
                game.play(move.x, move.y);
                return;
            }
        }

        for (const auto& move : availableMoves) {
            GameState temp = game;
            temp.play(move.x, move.y);
            if (temp.hasWon(1)) {
                game.play(move.x, move.y);
                return;
            }
        }

        srand(static_cast<unsigned int>(time(0)));
        int randIdx = rand() % availableMoves.size();
        game.play(availableMoves[randIdx].x, availableMoves[randIdx].y);
    }
};

#endif
