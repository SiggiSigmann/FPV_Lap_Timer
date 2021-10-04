#include "TrackMenu.h"

TrackMenu::TrackMenu(Adafruit_SSD1306* d, Menu* m, TrackManager* t):MenuList(d,m,3){
	tm = t;
}

void TrackMenu::draw(){
	//top
	this->display->setCursor(0,0);
	this->display->print("TRACK - MENU:");

	byte idx = 0;
	drawPoint(idx++,"Record Track");
	drawPoint(idx++,"View Track");
	drawPoint(idx++,"Select: " + String(this->tm->getSelected()));
}	

void TrackMenu::buttonNext(){
	switch (activePoint){
		case 0:

			break;
		case 1:

			break;
		case 2:
			editNumber = true;
			break;
	}
}

void TrackMenu::buttonUp(){
	if(editNumber){
		byte number = this->tm->getSelected();
		if(number == 0 ){
			number = this->tm->getTrackNumber()-1;
		}else{
			number--;
		}
		this->tm->setselected(number);
	}else{
		if(this->activePoint == 0 ){
			this->activePoint= getNumberOfPoints()-1;
		}else{
			this->activePoint--;
		}
	}
}

void TrackMenu::buttonDown(){
	if(editNumber){
		byte number = this->tm->getSelected();
		number++;
		if(number>=this->tm->getTrackNumber()){
			number = 0;
		}
		this->tm->setselected(number);
	}else{
		activePoint++;
		activePoint %=getNumberOfPoints();
	}
}

void TrackMenu::buttonPrev(){
	if(editNumber){
		editNumber = false;
	}else{
		this->parent->acitvateMe();
	}
}

