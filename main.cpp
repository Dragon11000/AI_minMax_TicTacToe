#include <iostream>
#include "Board.hpp"
#include "minMaxAI.hpp"
#include "bash.hpp"

using namespace std;

void play(Board b, int numberOfPlayers, Piece aiSide);

int main(int argc, char const *argv[]) {
    /* code */
    Board b1 = Board();
    bool flag = true;

    while(flag) {
        play(b1, 1, O);
        std::string responce;

        std::cout << "Would you like to play again? (y/n) ";
        getline(std::cin, responce);

        if(responce != "y") {
            flag = false;
        }
    }

    std::cout << "Thank you for playing!" << std::endl;

    return 0;
}

void play(Board b, int numberOfPlayers, Piece aiSide) {
    b.resetBoard();

    bool flag = true;
    while(flag) {
        b.printBoard();

        std::cout << "Player ";
        switch(b.getCurrentPlayer()) {
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
                std::cout << "Error";
                break;
        }


        //If AI's Turn
        if(numberOfPlayers == 0) {
            tttAI ai = tttAI(b, b.getCurrentPlayer());
            ai.createTree();

            int aiMove = ai.getBestMove();
            std::cout << std::endl << "AI placed at " << aiMove << std::endl;
            b.playerTurn(aiMove);
        } else if(numberOfPlayers == 1 && b.getCurrentPlayer() == aiSide) {
            tttAI ai = tttAI(b);
            ai.createTree();
            int aiMove = ai.getBestMove();
            std::cout << std::endl << "AI placed at " << aiMove << std::endl;
            b.playerTurn(aiMove);

        } else {
            std::string responce;

            do {
                std::cout << std::endl << "Input number between (0-8)";
                std::cout << std::endl << "To quit type q.";
                std::cout << std::endl << "Where do you want to place your piece? ";
                getline(std::cin, responce);
            } while(!b.validateRespose(responce));

            if(responce == "q" || responce == "Q") {
                return;
            } else {
                int place = stoi(responce);
                b.playerTurn(place);
            }
        }

        if(!b.canContinue()) {
            flag = false;
        }
    }

    b.printBoard();
    b.printWinner();
}
