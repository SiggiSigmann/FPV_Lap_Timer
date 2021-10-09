#include "AbstractMenu.h"

AbstractMenu::AbstractMenu(String name){
	this->name = name;
	this->name.toUpperCase();
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