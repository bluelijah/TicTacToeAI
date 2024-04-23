#ifndef BOARD_H
#define BOARD_H

#include <iostream>

enum SquareSpot {EMPTY, PLAYER1, PLAYER2};

struct Board {
private:
    int size;
    SquareSpot **grid;
    
    
    void ticGrid() {
        grid = new SquareSpot*[size];

        for (int i = 0; i < size; i++) {
            grid[i] = new SquareSpot[size];
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = EMPTY;
            }
        }
    }

public:
    
    Board() {
        
        size = 3;
        ticGrid();
    }


    Board(int size) {
       
        this->size = size;
        ticGrid();
    }

    
    Board(const Board& other) {
        
        size = other.size;
        ticGrid();

        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = other.grid[i][j];
            }
        }
    }

   
    Board& operator=(const Board& other) {
        if (size == other.size) {
            
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    grid[i][j] = other.grid[i][j];
                }
            }
        } else {
            for (int i = 0; i < size; i++) {
                delete[] grid[i];
            }
            delete[] grid;

            size = other.size;
            ticGrid();

            
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    grid[i][j] = other.grid[i][j];
                }
            }
        }
        return *this;
    }

    
    bool operator==(const Board& other) {
        if (size != other.size) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j] != other.grid[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    int getSize() const {
        return size;
    }

    
    ~Board() {
        for (int i = 0; i < size; i++) {
            delete[] grid[i];
        }
        delete[] grid;
    }

    
    bool update(int x, int y, SquareSpot player) {
        if (x < 0 || x >= size || y < 0 || y >= size) {
            return false;
        }

        if (grid[x][y] != EMPTY) {
            return false;
        }

        grid[x][y] = player;
        return true;
    }

    // check if winner
    bool isWinner(SquareSpot player) const {
        for (int i = 0; i < size; i++){
            bool fullRow = true;
            for (int j = 0; j < size; j++){
                if (grid[i][j] != player){
                    fullRow = false;
                }
            }
            if (fullRow) return true;
        }


        for (int i = 0; i < size; i++){
            bool fullCol = true;
            for (int j = 0; j < size; j++){
                if (grid[j][i] != player){
                    fullCol = false;
                }
            }
            if (fullCol) return true;
        }

        bool topDiag = true;
        for (int i = 0; i < size; i++){
            if (grid[i][i] != player){
                topDiag = false;
            }
        }
        if (topDiag) return true;

        bool botDiag = true;
        for (int i = 0; i < size; i++){
            if (grid[i][size - 1 -i] != player){
                botDiag = false;
            }
        }
        if (botDiag) return true;

        return false;
    }

    bool full() const {
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                if (grid[i][j] == EMPTY){
                    return false;
                }
            }
        }
        return true;
    }

    friend std::ostream& operator<<(std::ostream&, const Board&);
};

// overloaded shift left operator
std::ostream& operator<<(std::ostream& os, const Board& board){
    os << "   ";
    for (int j = 0; j < board.size; j++){
        os << " " << j << "  ";
    }
    os << std::endl;
    os << "   ";
    for (int j = 0; j < board.size; j++){
        os << "--- ";
    }
    os << std::endl;
    for (int i = 0; i < board.size; i++){
        os << i << " ";
        for (int j = 0; j < board.size; j++){
            char c = ' ';
            if (board.grid[i][j] == PLAYER1){
                c = 'X';
            }
            else if (board.grid[i][j] == PLAYER2){
                c = 'O';
            }
            os << "| " << c << " ";
            if (j == board.size - 1) os << "|";
        }
        os << std::endl << "   ";
        for (int j = 0; j < board.size; j++){
            os << "--- ";
        }
        os << std::endl;
    }

    return os;
}

#endif