#include "MenuWindow.h"

MenuWindow::MenuWindow(String name, AbstractMenu* m):AbstractMenu(name){
	this->parent = m;
};

//set parent to parent MenuWindow
void MenuWindow::setParent(AbstractMenu* parent){
	this->parent = parent;
}

//activate this
void MenuWindow::acitvateMe(){
	this->parent->acitvate(this);
	display.clearDisplay();
}

//activate given menu
void MenuWindow::acitvate(AbstractMenu* activateion){
	this->parent->acitvate(activateion);
	display.clearDisplay();
}

//defoult action for prev button.
//can be overwritten but this->parent->acitvateMe(); mussbe called 
void MenuWindow::buttonPrev(){
	this->parent->acitvateMe();
}