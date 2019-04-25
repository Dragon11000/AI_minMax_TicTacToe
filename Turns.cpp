#include "Turns.hpp"

Turns::Turns() {
	head = nullptr;
}

/*Turns::~Turns() {
	while(head != nullptr) {
		Node* delItem = head;
		head = head->next;
		delete delItem;
	}
}*/

bool Turns::isEmpty() {
	if(head == nullptr) {
		return true;
	}
	return false;
}

void Turns::push(int move) {
	Turn* newItem = new Turn;
	newItem->move = move;

	if(isEmpty()) {
		head = newItem;
		newItem->next = nullptr;
	} else {
		newItem->next = head;
		head = newItem;
	}
}

void Turns::pop() {
	if(isEmpty()) {
		std::cout << "Stack empty, cannot pop an item." << std::endl;
		return;
	}

	Turn* delItem = head;
	head = head->next;
	delete delItem;
}

int Turns::peek() {
	if(isEmpty()) {
		std::cout << "Stack empty, cannot peek." << std::endl;
		return -1;
	}
	return head->move;
}
