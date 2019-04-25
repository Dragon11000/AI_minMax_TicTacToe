#ifndef Turns_hpp
#define Turns_hpp

#include <iostream>
#include "bash.hpp"

struct TurnNode {
    /* data */
    int move;
    TurnNode* next;
};


class Turns {
private:
    TurnNode* head = nullptr;

public: 
    Turns();
    bool isEmpty();
    void push(int key);
    void pop();
    int peek();
};

#endif /* Turns_hpp */
