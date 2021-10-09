#include "Trackersettings.h"

TrackerSettings::TrackerSettings(AbstractMenu* m, LapTracker* tracker):SubMenuList("TRACKER SETTINGS",m,3){
	this->tracker = tracker;
}

void TrackerSettings::draw(){
	byte idx=0;
	drawPoint(idx++,"Upper: " +String(tracker->getUpper())+"%");
	drawPoint(idx++,"Lower: " +String(tracker->getLower())+"%");
	drawPoint(idx++,"Reset Times");
}

void TrackerSettings::buttonNext(){
	switch (activePoint){
		case 0:
			editUpper = true;
			break;
		case 1:
			editLower = true;
			break;
		case 2:
			tracker->resetTimes();
			break;
	}
}

void TrackerSettings::buttonUp(){
	if(editUpper){
		int number = tracker->getUpper();
		if((number-1) <= tracker->getLower() ){
			number = 100;
		}else{
			number--;
		}
		tracker->setUpper(number);
	}else if(editLower){
		int number = tracker->getLower();
		if(number == 0 ){
			number = tracker->getUpper()-1;
		}else{
			number--;
		}
		tracker->setLower(number);
	}else{
		SubMenuList::buttonUp();
		/*if(this->activePoint == 0 ){
			this->activePoint= getNumberOfPoints()-1;
		}else{
			this->activePoint--;
		}*/
	}
}

void TrackerSettings::buttonDown(){
	if(editUpper){
		int number =  tracker->getUpper();
		number++;
		if(number>100){
			number = tracker->getLower() + 1;
		}
		tracker->setUpper(number);
	}else if(editLower){
		int number =  tracker->getLower();
		number++;
		if(number>=tracker->getUpper()){
			number = 0;
		}
		tracker->setLower(number);
	}else{
		SubMenuList::buttonDown();
		//activePoint++;
		//activePoint %=getNumberOfPoints();
	}
}

void TrackerSettings::buttonPrev(){
	if(editUpper){
		editUpper = false;
	}else if(editLower){
		editLower = false;
	}else{
		this->parent->acitvateMe();
	}
}