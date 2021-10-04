#include "MenuWindow.h"

MenuWindow::MenuWindow(Adafruit_SSD1306* d, AbstractMenu* m):AbstractMenu(d){
	this->parent = m;
};

//set parent to parent MenuWindow
void MenuWindow::setParent(AbstractMenu* parent){
	this->parent = parent;
}

//activate this
void MenuWindow::acitvateMe(){
	this->parent->acitvate(this);
	this->display->clearDisplay();
}

//activate given menu
void MenuWindow::acitvate(AbstractMenu* activateion){
	this->parent->acitvate(activateion);
	this->display->clearDisplay();
}

//defoult action for prev button.
//can be overwritten but this->parent->acitvateMe(); mus be called 
void MenuWindow::buttonPrev(){
	this->parent->acitvateMe();
}