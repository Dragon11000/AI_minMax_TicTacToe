#include "minMaxAI.hpp"

tttAI::tttAI() {
    head = nullptr;
}

tttAI::tttAI(Board b) {
    head = createNode(-1, 0, b, nullptr, nullptr, nullptr);
}

tttAI::tttAI(Board b, Piece ai) {
    head = createNode(-1, 0, b, nullptr, nullptr, nullptr);
    aiPiece = ai;
}

void tttAI::createTree() {
    if(head == nullptr) {
        return;
    }
    createTree(head);
}

void tttAI::createTree(Node* currNode) {
    if(!(currNode->board).canContinue()) {
        return;
    }

    for(int i = 0; i < 9; i++) {
        if((currNode->board).getPostion(i) == B) {
            Board newBoard = createBoardFromBoard(currNode->board);
            newBoard.playerTurn(i);
            int moveValue = 0;

            if(!newBoard.canContinue()) {
                Piece winner = newBoard.checkWinner();
                if(winner == aiPiece) {
                    moveValue = 1 * newBoard.remainingSpots();
                } else {
                    moveValue = -2 * newBoard.remainingSpots();
                }
            }

            Node* newNode = addChild(currNode, i, moveValue, newBoard);

            createTree(newNode);
        }
    }
}

Node* tttAI::addChild(Node* parent, int move, int moveValue, Board board) {
    Node* newNode = createNode(move, moveValue, board, parent, nullptr, nullptr);

    Node* temp = parent->firstChild;
    if(temp == nullptr) {
        parent->firstChild = newNode;
    } else {
        while(temp->nextSib != nullptr) {
            temp = temp->nextSib;
        }
        temp->nextSib = newNode;
    }
    return newNode;
}

Node* tttAI::createNode(int m, int mV, Board b, Node* p, Node* nS, Node* nC) {
    Node* newNode = new Node;
    newNode->move = m;
    newNode->moveValue = mV;
    newNode->board = b;
    newNode->parent = p;
    newNode->nextSib = nS;
    newNode->firstChild = nC;
    return newNode;
}


Board tttAI::createBoardFromBoard(Board x) {
    Board newBoard = Board();
    newBoard.copyFromBoard(x);
    return x;
}

void tttAI::calcMoveValue(Node* currNode, Piece currPlayer) {
    if(currNode == nullptr) {
        return;
    }

    if(currNode->firstChild != nullptr) {
        calcMoveValue(currNode->firstChild, oppositePiece(currPlayer));
    }

    Node* minNode = minChild(currNode);
    Node* maxNode = maxChild(currNode);

    if(currPlayer != aiPiece && minNode != nullptr) {
        currNode->moveValue = minNode->moveValue;
    } else if(currPlayer == aiPiece && maxNode != nullptr) {
        currNode->moveValue = maxNode->moveValue;
    }

    if(currNode->nextSib != nullptr) {
        calcMoveValue(currNode->nextSib, currPlayer);
    }
}

Piece tttAI::oppositePiece(Piece p) {
    if(p == O) {
        return X;
    } else if(p == X) {
        return O;
    } else {
        return B;
    }
}

int tttAI::getBestMove() {
    calcMoveValue(head, aiPiece);
    return maxChild(head)->move;
}


Node* tttAI::minChild(Node* currNode) {
    Node* temp = currNode->firstChild;
    Node* min = temp;

    while(temp != nullptr) {
        if(temp->moveValue < min->moveValue) {
            min = temp;
        }
        temp = temp->nextSib;
    }
    return min;
}

Node* tttAI::maxChild(Node* currNode) {
    Node* temp = currNode->firstChild;
    Node* max = temp;

    while(temp != nullptr) {
        if(temp->moveValue > max->moveValue) {
            max = temp;
        }
        temp = temp->nextSib;
    }
    return max;
}

void tttAI::printTree() {
    printTree(head);
}
void tttAI::printTree(Node* currNode) {
    if(currNode == nullptr) {
        return;
    }

    std::cout << currNode->move << currNode->moveValue << " -> ";
    printTree(currNode->nextSib);

    std::cout << std::endl;
    printTree(currNode->firstChild);
}
