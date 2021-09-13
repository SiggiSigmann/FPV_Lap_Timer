#include "MenuPoint.h"

MenuPoint::MenuPoint(Adafruit_SSD1306* d, Menu* m):Menu(d){
	Serial.println("huaa2");
	this->parent = m;
};

void MenuPoint::setParent(Menu* parent){
	this->parent = parent;
}

void MenuPoint::acitvateMe(){
	this->parent->acitvate(this);
	this->display->clearDisplay();
}

void MenuPoint::acitvate(Menu* activateion){
	this->parent->acitvate(activateion);
	this->display->clearDisplay();
}