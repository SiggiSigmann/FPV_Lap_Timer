#include "SubMenuList.h"

SubMenuList::SubMenuList(String name, AbstractMenu* m, byte numberOfPoints):MenuWindow(name,m){
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
	display.fillRect(4,menuX,px,8,BLACK);
	display.setCursor(18,menuX);
	display.drawRect(4,menuX,8,8,WHITE);
	display.print(name);
	if(activePoint == i){
		display.fillRect(4,menuX,8,8,WHITE);
	}
}

void SubMenuList::drawInfo(byte i, String name, int px){
	byte menuX = 18;
	menuX += (i*12);
	display.fillRect(4,menuX,px,8,BLACK);
	display.setCursor(18,menuX);
	display.print(name);
}

byte SubMenuList::getNumberOfPoints(){
	return numberOfPoints;
}