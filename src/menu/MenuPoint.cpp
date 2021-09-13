#include "MenuPoint.h"

MenuPoint::MenuPoint(Adafruit_SSD1306* d):Menu(d){
	Serial.println("huaa2");
};

void MenuPoint::setParent(Menu* parent){
	this->parent = parent;
}

void MenuPoint::acitvateMe(){
	this->parent->acitvate(this);
}

void MenuPoint::acitvate(Menu* activateion){
	this->parent->acitvate(activateion);
}