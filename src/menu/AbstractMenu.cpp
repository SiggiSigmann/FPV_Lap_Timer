#include "AbstractMenu.h"

AbstractMenu::AbstractMenu(Adafruit_SSD1306* d, String name){
	display = d;
	this->name = name;
	this->name.toUpperCase();
}

Adafruit_SSD1306* AbstractMenu::getDisplay(){
	return display;
}

String AbstractMenu::getName(){
	return name;
}

String AbstractMenu::getExtra(){
	return extra;
}

void AbstractMenu::setExtra(String extra){
	this->extra = extra;
}