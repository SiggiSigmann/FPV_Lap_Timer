#include "SubMenuList.h"

SubMenuList::SubMenuList(String name, AbstractMenu* m):MenuWindow(name,m){
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

void SubMenuList::drawPoint(String name, int px){
	options++;
	byte menuX = 18;
	menuX += (idx*12);
	display.fillRect(4,menuX,px,8,BLACK);
	display.setCursor(18,menuX);
	display.drawRect(4,menuX,8,8,WHITE);
	display.print(name);
	if(activePoint == idx++){
		display.fillRect(4,menuX,8,8,WHITE);
	}
}

void SubMenuList::drawInfo(String name, int px){
	byte menuX = 18;
	menuX += (idx++*12);
	display.fillRect(4,menuX,px,8,BLACK);
	display.setCursor(18,menuX);
	display.print(name);
}

byte SubMenuList::getNumberOfPoints(){
	return numberOfPoints;
}

void SubMenuList::draw(){
	display.drawFastVLine(1,18,44,WHITE);
	drawMenu();
	numberOfPoints = options;
	options=0;
	idx = 0;
}