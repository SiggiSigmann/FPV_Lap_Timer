#include "MenuList.h"

MenuList::MenuList(Adafruit_SSD1306* d, Menu* m, byte numberOfPoints):MenuPoint(d,m){
	this->numberOfPoints = numberOfPoints;
}

void MenuList::buttonUp(){
	if(this->activePoint ==0){
		this->activePoint = numberOfPoints-1;
	}else{
		this->activePoint--;
	}
}

void MenuList::buttonDown(){
	this->activePoint++;
	this->activePoint %= numberOfPoints;
}

void MenuList::drawPoint(byte i, String name){
	byte menuX = 18;
	menuX += (i*12);
	this->display->fillRect(4,menuX,120,8,BLACK);
	this->display->setCursor(18,menuX);
	this->display->drawRect(4,menuX,8,8,WHITE);
	this->display->print(name);
	if(activePoint == i){
		this->display->fillRect(4,menuX,8,8,WHITE);
	}
}

void MenuList::drawInfo(byte i, String name){
	byte menuX = 18;
	menuX += (i*12);
	this->display->fillRect(4,menuX,120,8,BLACK);
	this->display->setCursor(18,menuX);
	this->display->print(name);
}

byte MenuList::getNumberOfPoints(){
	return numberOfPoints;
}