#include "StackController.h"

StackController::StackController(){
	stack = new LinkedList<Window*>();
}
StackController::~StackController(){
	//delete stack;
}

void StackController::push(Window* newWindow){
	this->stack->add(newWindow);
}

Window* StackController::pop(){
	return this->stack->pop();
}

int StackController::getSize(){
	return this->stack->size();
}