#include "Frame.h"

Frame::Frame(String name, GUI* parentMenu):GUI(name){
	this->parentMenu = parentMenu;
};

//set parent to parent MenuWindow
void Frame::setParent(GUI* parentMenu){
	this->parentMenu = parentMenu;
}

//activate this
void Frame::acitvateMe(){
	this->parentMenu->acitvate(this);
	display.clearDisplay();
}

//activate given menu
void Frame::acitvate(GUI* activateion){
	this->parentMenu->acitvate(activateion);
	display.clearDisplay();
}

//defoult action for prev button.
//can be overwritten but this->parent->acitvateMe(); mussbe called 
void Frame::buttonPrev(){
	this->parentMenu->acitvateMe();
}