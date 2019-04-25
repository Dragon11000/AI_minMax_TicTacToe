#ifndef minMaxAI_hpp
#define minMaxAI_hpp

#include <iostream>
#include "bash.hpp"
#include "Board.hpp"

struct Node {
    /* data */
    int move;
    int moveValue;
    Board board;
    Node* parent;
    Node* nextSib;
    Node* firstChild;
};


class tttAI {
private:
    Node* head = nullptr;
    Piece aiPiece = O;
public:
    tttAI();
    tttAI(Board b);
    tttAI(Board b, Piece ai);

    void createTree();
    void createTree(Node* currNode);
    Node* addChild(Node* parent, int move, int moveValue, Board board);
    Node* createNode(int m, int mV, Board b, Node* p, Node* nS, Node* nC);
    Board createBoardFromBoard(Board x);

    void calcMoveValue(Node* currNode, Piece currPlayer);
    Piece oppositePiece(Piece p);
    void sumChild(Node* currNode);

    int getBestMove();
    Node* minChild(Node* currNode);
    Node* maxChild(Node* currNode);

    void printTree();
    void printTree(Node* currNode);
};

#endif /* minMaxAI_hpp */
