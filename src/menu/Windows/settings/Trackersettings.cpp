#include "Trackersettings.h"

TrackerSettings::TrackerSettings(AbstractMenu* m):SubMenuList("TRACKER SETTINGS",m){
}

void TrackerSettings::drawMenu(){
	drawPoint("Upper: " +String(lapTracker->getUpper())+"%");
	drawPoint("Lower: " +String(lapTracker->getLower())+"%");
	drawPoint("Reset Times");
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
			lapTracker->resetTimes();
			break;
	}
}

void TrackerSettings::buttonUp(){
	if(editUpper){
		int number = lapTracker->getUpper();
		if((number-1) <= lapTracker->getLower() ){
			number = 100;
		}else{
			number--;
		}
		lapTracker->setUpper(number);
	}else if(editLower){
		int number = lapTracker->getLower();
		if(number == 0 ){
			number = lapTracker->getUpper()-1;
		}else{
			number--;
		}
		lapTracker->setLower(number);
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
		int number =  lapTracker->getUpper();
		number++;
		if(number>100){
			number = lapTracker->getLower() + 1;
		}
		lapTracker->setUpper(number);
	}else if(editLower){
		int number =  lapTracker->getLower();
		number++;
		if(number>=lapTracker->getUpper()){
			number = 0;
		}
		lapTracker->setLower(number);
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
		SubMenuList::buttonPrev();
	}
}