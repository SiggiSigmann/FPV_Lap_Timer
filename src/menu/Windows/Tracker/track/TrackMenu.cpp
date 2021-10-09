#include "TrackMenu.h"

TrackMenu::TrackMenu(AbstractMenu* m, TrackManager* t):SubMenuList("TRACK - MENU",m,3){
	tm = t;
}

void TrackMenu::draw(){
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
		SubMenuList::buttonUp();
		/*if(this->activePoint == 0 ){
			this->activePoint= getNumberOfPoints()-1;
		}else{
			this->activePoint--;
		}*/
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
		SubMenuList::buttonDown();
		//activePoint++;
		//activePoint %=getNumberOfPoints();
	}
}

void TrackMenu::buttonPrev(){
	if(editNumber){
		editNumber = false;
	}else{
		this->parent->acitvateMe();
	}
}

