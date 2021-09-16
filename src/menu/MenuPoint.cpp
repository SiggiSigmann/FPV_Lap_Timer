#include "MenuPoint.h"

MenuPoint::MenuPoint(Adafruit_SSD1306* d, Menu* m):Menu(d){
	this->parent = m;
};

//set parent to parent MenuPoint
void MenuPoint::setParent(Menu* parent){
	this->parent = parent;
}

//activate this
void MenuPoint::acitvateMe(){
	this->parent->acitvate(this);
	this->display->clearDisplay();
}

//activate given menu
void MenuPoint::acitvate(Menu* activateion){
	this->parent->acitvate(activateion);
	this->display->clearDisplay();
}

//defoult action for prev button.
//can be overwritten but this->parent->acitvateMe(); mus be called 
void MenuPoint::buttonPrev(){
	this->parent->acitvateMe();
}