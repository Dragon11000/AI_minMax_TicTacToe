#include "Board.hpp"

Board::Board() {
    size = 3;
    currentPlayer = X;

    resetBoard();
    //turn = tttTurns();
}

//Prints Board in the iostream
void Board::printBoard() {
    std::cout << std::endl;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            int index = j+(i*size);
            Piece p = positions[index];
            std::cout << " ";
            switch (p) {
                case B:
                    std::cout << index;
                    break;
                case X:
                    bash::changeTextCyan();
                    std::cout << "X";
                    bash::changeTextDefault();
                    break;
                case O:
                    bash::changeTextRed();
                    std::cout << "O";
                    bash::changeTextDefault();
                    break;
                default:
                    std::cout << index;
                    break;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//Sets all spots to blank(B)
void Board::resetBoard() {
    for(int i = 0; i < size*size; i++) {
        positions[i] = B;
    }
}

//Bypass
void Board::placePiece(int on, Piece type) {
    positions[on] = type;
}

bool Board::placeAvalible(int index) {
    if(positions[index] == B) {
        return true;
    } else {
        return false;
    }
}

void Board::nextTurn() {
    if(currentPlayer == X) {
        currentPlayer = O;
    } else if(currentPlayer == B) {
        std::cout << "ERROR!!!!! - currentPlayer should never by blank (B)";
    } else {
        currentPlayer = X;
    }
}

void Board::playerTurn(int place) {
    if(placeAvalible(place)) {
        placePiece(place, currentPlayer);
        nextTurn();
    } else {
        bash::changeTextRed();
        std::cout << "Spot already played." << std::endl;
        bash::changeTextDefault();
    }
}

bool Board::canContinue() {
    Piece winner = checkWinner();
    if(winner != B) {
        return false;
    }

    for(int i = 0; i < size*size; i++) {
        if(positions[i] == B) {
            return true;
        }
    }

    return false;
}

Piece Board::checkWinner() {
    //Horizontal
    for(int i = 0; i < size; i++) {
        if(positions[i*size] != B && positions[i*size] == positions[i*size+1] && positions[i*size] == positions[i*size+2]) {
            return positions[i*size];
        }
    }

    //Vertical
    for(int i = 0; i < size; i++) {
        if(positions[i] != B && positions[i] == positions[i+size] && positions[i] == positions[i+(2*size)]) {
            return positions[i];
        }
    }

    //Diagonal
    if(positions[0] != B && positions[0] == positions[size+1] && positions[0] == positions[(2*size) + 2]) {
        return positions[0];
    }
    if(positions[2] != B && positions[2] == positions[2+size-1] && positions[2] == positions[2+(2*size) - 2]) {
        return positions[2];
    }
    return B;
}

void Board::printWinner() {
    Piece winner = checkWinner();
    switch (winner) {
        case X:
            bash::changeTextCyan();
            std::cout << "Player X Wins!" << std::endl;
            bash::changeTextDefault();
            break;
        case O:
            bash::changeTextRed();
            std::cout << "Player O Wins!" << std::endl;
            bash::changeTextDefault();
            break;
        default:
            std::cout << "Draw" << std::endl;
            break;
    }
}

int Board::remainingSpots() {
    int count = 0;
    for(int i = 0; i < 9; i++) {
        if(positions[i] == B) {
            count++;
        }
    }
    return count;
}

Piece Board::getPostion(int index) {
    return positions[index];
}

Piece Board::getCurrentPlayer() {
    return currentPlayer;
}

void Board::copyFromBoard(Board x) {
    for(int i = 0; i < 9; i++) {
        positions[i] = x.getPostion(i);
        currentPlayer = x.getCurrentPlayer();
    }
}

bool Board::validateRespose(std::string s) {
    std::string good[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "q", "Q"};
    int c = 11;

    for(int i = 0; i < c; i++) {
        if(s == good[i]) {
            return true;
        }
    }

    return false;
}
