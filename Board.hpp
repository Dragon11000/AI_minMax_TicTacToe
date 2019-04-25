#ifndef Board_hpp
#define Board_hpp

#include <iostream>
//#include "ttt_turns.hpp"
#include "bash.hpp"

enum Piece {B, X, O};

class Board {
private:
    /* data */
    int size;
    Piece positions[9];
    Piece currentPlayer;
    //tttTurns turn;

public:
    Board();

    void printBoard();
    void resetBoard();

    void placePiece(int on, Piece type);
    bool placeAvalible(int index);

    void nextTurn();
    void playerTurn(int place);
    bool canContinue();
    Piece checkWinner();
    void printWinner();
    int remainingSpots();

    bool validateRespose(std::string s);

    Piece getPostion(int index);
    Piece getCurrentPlayer();
    void copyFromBoard(Board x);
};

#endif /* Board_hpp */
