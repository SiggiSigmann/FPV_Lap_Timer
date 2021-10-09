#include "SubMenuList.h"

SubMenuList::SubMenuList(String name, AbstractMenu* m):MenuWindow(name,m){
}

void SubMenuList::buttonUp(){
	if(this->activePoint ==0){
		this->activePoint = numberOfPoints-1;
		displaoffset = numberOfPoints-4;
	}else{
		this->activePoint--;
		if(activePoint<displaoffset){
			displaoffset--;
		}
	}
}

void SubMenuList::buttonDown(){
	this->activePoint++;
	if(this->activePoint>=numberOfPoints){
		activePoint=0;
		displaoffset=0;
	}else{
		if(activePoint>=(displaoffset+4)){
			displaoffset++;
		}
	}
}

void SubMenuList::drawPoint(String name, int px){
	options++;
	if(!((options > displaoffset) && (options <= (displaoffset+4)))){
		return;
	}

	byte menuX = 18;
	menuX += (idx*12);
	display.fillRect(4,menuX,px,8,BLACK);
	display.setCursor(18,menuX);
	display.drawRect(4,menuX,8,8,WHITE);
	display.print(name);
	if(activePoint == (idx+displaoffset)){
		display.fillRect(4,menuX,8,8,WHITE);
	}
	idx++;
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
	drawMenu();
	numberOfPoints = options;


	if(options>4){
		//delete old 
		display.fillRect(0,18,3,62,BLACK);

		//draw sliderline
		display.drawFastVLine(1,18,44,WHITE);

		//calc sliderlength
		//if there are more then 11 operion then the siderlength will be fix
		byte sliderlength;
		if(numberOfPoints>11){
			sliderlength = 4;
		}else{
			sliderlength = 44 / (numberOfPoints-4);
		}
		//calc position

		//calc pixels per option which are not shown (therfore the -4)
		byte position = (44-sliderlength)/(numberOfPoints-4);
		
		//calc the offset amount of pixels
		position *= displaoffset;
		position+=18;

		//enshure to reach bottom end
		if(activePoint==(numberOfPoints-1)){
			position = 62-sliderlength;
		}

		display.fillRect(0,position,3,sliderlength,WHITE);
	}

	options=0;
	idx = 0;
}