#include "Menu.h"

Menu::Menu(String headline, GUI* parent):Frame(headline, parent){
}

//select next menu entry, if end is reach jump to first and vice versa
void Menu::buttonUp(){
	if(this->activeEntry ==0){
		//jump to bottom
		this->activeEntry = activeEntry-1;

		//move offset
		entryOffsetToScrall = numberOfMenuEntries-4;
	}else{
		this->activeEntry--;

		//move offset
		if(activeEntry<entryOffsetToScrall){
			entryOffsetToScrall--;
		}
	}
}

//select prev menu entry, if end is reach jump to first and vice versa
void Menu::buttonDown(){
	//move selection
	this->activeEntry++;
	if(this->activeEntry>=numberOfMenuEntries){
		activeEntry=0;
		
		//move offset
		entryOffsetToScrall=0;
	}else{
		if(activeEntry>=(entryOffsetToScrall+4)){

			//move offset
			entryOffsetToScrall++;
		}
	}
}

boolean Menu::isMenuEntryDrawingNeeded(){
	if(!((currentMenuEntry > entryOffsetToScrall) && (currentMenuEntry <= (entryOffsetToScrall+4)))){
		return false;
	}

	return true;
}

void Menu::drawPoint(String name, int px){
	currentMenuEntry++;
	//cehck if drawing is not needed
	if(!this->isMenuEntryDrawingNeeded()){
		return;
	}

	//calc x position
	byte menuX = 18;
	menuX += (drawingIdx*12);				//ech

	//draw
	display.fillRect(4,menuX,px,8,BLACK);
	display.setCursor(18,menuX);
	display.drawRect(4,menuX,8,8,WHITE);
	display.print(name);

	//fill rect if point is selected
	if(activeEntry == (drawingIdx+entryOffsetToScrall)){
		display.fillRect(4,menuX,8,8,WHITE);
	}
	drawingIdx++;
}

void Menu::drawInfo(String name, int px){
	currentMenuEntry++;
	//cehck if drawing is not needed
	if(!this->isMenuEntryDrawingNeeded()){
		return;
	}

	byte menuX = 18;
	menuX += (drawingIdx*12);
	display.fillRect(4,menuX,px,8,BLACK);
	display.setCursor(18,menuX);
	display.print(name);

	display.drawFastHLine(4,menuX+2,6,BLACK);
	if(activeEntry == (drawingIdx+entryOffsetToScrall)){
		display.drawFastHLine(4,menuX+2,8,WHITE);
	}
	drawingIdx++;
}

byte Menu::getNumberOfPoints(){
	return numberOfMenuEntries;
}

void Menu::drawScrollBar(){
	//check if scrollbar is needed
	if(currentMenuEntry>4){
		//delete old 
		display.fillRect(0,18,3,62,BLACK);

		//draw sliderline
		display.drawFastVLine(1,18,44,WHITE);

		//calc sliderlength
		//if there are more then 11 operion then the siderlength will be fix
		byte sliderlength;
		if(numberOfMenuEntries>11){
			sliderlength = 4;
		}else{
			sliderlength = 44 / (numberOfMenuEntries-3);
		}
		//calc position

		//calc pixels per option which are not shown (therfore the -4)
		int position = numberOfMenuEntries*(44-sliderlength);
		
		//calc the offset amount of pixels
		position /= (numberOfMenuEntries-4);
		position+=18;

		//enshure to reach bottom end
		if(activeEntry==(numberOfMenuEntries-1)){
			position = 62-sliderlength;
		}

		display.fillRect(0,position,3,sliderlength,WHITE);
	}
}

void Menu::draw(){

	//draw Menu entrys => method defind by child class
	drawMenu();
	numberOfMenuEntries = currentMenuEntry;

	drawScrollBar();

	currentMenuEntry=0;
	drawingIdx = 0;
}