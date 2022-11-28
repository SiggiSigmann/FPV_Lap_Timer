#include "Menu.h"

Menu::Menu(String headline):Window(headline){
	entries = new LinkedList<MenuEntry>();
}

// manage entries ###############################################################################################
void Menu::addEntry(MenuEntry entry){
	entries->add(entry);
}

void Menu::remove(short idx){
	entries->remove(idx);
}

// window stuff ###############################################################################################
void Menu::draw(){
	this->drawingIdx = 0;

	short amount = entries->size()<  4 ?  entries->size() : 4;

	for(int i=0;i<amount;i++){
		MenuEntry entry = entries->get(i+scrollingOffset);
		switch (entry.type){
			case 0:
				drawPoint(entry.text);
				break;
			case 1:
				drawInfo(entry.text);
				break;
			case 2:
				drawPoint(entry.text);
				break;
		}
	}
	for(int i=0;i<4-amount;i++){
		clearPoint(i);
	}

	drawScrollBar();

	menuDraw();
}

void Menu::buttonUp(){
	if(disableFunctionality){
		menuButtonUp();
		return;
	}
	if(editValue){
		valueChangeUp(entries->get(selectedIdx+scrollingOffset).actionId);
		updateMenueEntry();
	}else{
		if(selectedIdx>0){
			selectedIdx--;
		}else if(scrollingOffset>0){ 
			scrollingOffset--;
		}
	}
}

void Menu::buttonDown(){
	if(disableFunctionality){
		menuButtonDown();
		return;
	}
	if(editValue){
		valueChangeDown(entries->get(selectedIdx+scrollingOffset).actionId);
		updateMenueEntry();
	}else{
		short amount = entries->size()<  4 ?  entries->size()-1 : 3;
		if(selectedIdx<amount){
			selectedIdx++;
		}else if(scrollingOffset<(entries->size()-4)){
			scrollingOffset++;
		}
	}
}

void Menu::buttonNext(){
	if(disableFunctionality){
		menuButtonNext();
		return;
	}
	if(!editValue){
		executeButtonAction();
	}
}

void Menu::buttonPrev(){
	if(disableFunctionality){
		menuButtonPrev();
		return;
	}
	if(editValue){
		editValue = false;
	}else{
		Window::buttonPrev();
	}
};

// drawing ##########################################################################################################
void Menu::drawScrollBar(){
	//delete old 
	display.fillRect(0,18,3,62,BLACK);
	if(entries->size()<5) return;



	//draw sliderline
	display.drawFastVLine(1,18,44,WHITE);

	byte sliderlength;
	if(entries->size()<12){
		sliderlength=44-(((entries->size()-4)*40)/8);
	}else{
		sliderlength=4;
	}

	//calc position
	//calc pixels per option which are not shown (therfore the -4)
	//calc the offset amount of pixels
	int remainingPixelsToslide = 44-sliderlength;
	int position = (remainingPixelsToslide * scrollingOffset)/ (entries->size()-4);
	position+=18;

	//enshure to reach bottom end
	if(scrollingOffset==(entries->size()-1)){
		position = 62-sliderlength;
	}

	display.fillRect(0,position,3,sliderlength,WHITE);
}

void Menu::clearPoint(short offset){
	byte menuX = 18;
	menuX += ((drawingIdx+offset)*12);

	//draw
	//delete old
	display.fillRect(4,menuX,SCREEN_WIDTH,8,BLACK);
}

void Menu::drawPoint(String name){
	byte menuX = 18;
	menuX += (drawingIdx*12);

	//draw
	//delete old
	display.fillRect(4,menuX,SCREEN_WIDTH,8,BLACK);

	//drawnew
	display.setCursor(18,menuX);
	display.drawRect(4,menuX,8,8,WHITE);
	display.print(name);

	//fill rect if point is selected
	if(drawingIdx == selectedIdx){
		if(!editValue){
			display.fillRect(4,menuX,8,8,WHITE);
		}else{
			display.drawFastHLine(4,menuX+3,8,WHITE);
		}
	}
	drawingIdx++;
}

void Menu::drawInfo(String name){

	byte menuX = 18;
	menuX += (drawingIdx*12);

	//delete old
	display.fillRect(4,menuX,SCREEN_WIDTH,8,BLACK);

	//draw new
	display.setCursor(18,menuX);
	display.print(name);
	display.drawFastHLine(4,menuX+2,6,BLACK);

	if(drawingIdx == selectedIdx){
		display.drawFastHLine(4,menuX+2,8,WHITE);
	}
	drawingIdx++;
}


// update #############################################################################################################
void Menu::executeButtonAction(){
	MenuEntry activeEntry = entries->get(selectedIdx+scrollingOffset);
	switch(activeEntry.type){
		case 2: 

			editValue = true;
			break;
		default:
			buttonAction(activeEntry.actionId);
	}
}

void Menu::updateMenueEntry(){
	MenuEntry activeEntry = entries->get(selectedIdx+scrollingOffset);
	String newTest =  updateEntry(activeEntry.actionId);
	activeEntry.text = newTest;
	entries->set(selectedIdx+scrollingOffset,activeEntry);
}

void Menu::setDisabled(bool state){
	disableFunctionality = state;
}

void Menu::updateAll(){
	for(int i =0; i<entries->size(); i++){
		MenuEntry activeEntry = entries->get(i);
		String newTest =  updateEntry(activeEntry.actionId);
		activeEntry.text = newTest;
		entries->set(i,activeEntry);
	}
}