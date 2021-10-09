#include "SubMenuList.h"

SubMenuList::SubMenuList(String name, Adafruit_SSD1306* d, AbstractMenu* m, byte numberOfPoints):MenuWindow(name,d,m){
	this->numberOfPoints = numberOfPoints;
}

void SubMenuList::buttonUp(){
	if(this->activePoint ==0){
		this->activePoint = numberOfPoints-1;
	}else{
		this->activePoint--;
	}
}

void SubMenuList::buttonDown(){
	this->activePoint++;
	this->activePoint %= numberOfPoints;
}

void SubMenuList::drawPoint(byte i, String name, int px){
	byte menuX = 18;
	menuX += (i*12);
	this->display->fillRect(4,menuX,px,8,BLACK);
	this->display->setCursor(18,menuX);
	this->display->drawRect(4,menuX,8,8,WHITE);
	this->display->print(name);
	if(activePoint == i){
		this->display->fillRect(4,menuX,8,8,WHITE);
	}
}

void SubMenuList::drawInfo(byte i, String name, int px){
	byte menuX = 18;
	menuX += (i*12);
	this->display->fillRect(4,menuX,px,8,BLACK);
	this->display->setCursor(18,menuX);
	this->display->print(name);
}

byte SubMenuList::getNumberOfPoints(){
	return numberOfPoints;
}