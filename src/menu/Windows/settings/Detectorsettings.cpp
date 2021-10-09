#include "Detectorsettings.h"

Detectorsettings::Detectorsettings(AbstractMenu* m):SubMenuList("DETECTOR SETTINGS",m){
}

void Detectorsettings::drawMenu(){
	drawPoint("ChannelsPM: " + String(droneDetector->getScannPM()));
	drawPoint("Reset");
	drawInfo("");
	drawInfo("Detected Drones:"+String(droneDetector->getNumberOfDrones()));
}

void Detectorsettings::buttonNext(){
	switch (activePoint){
		case 0:
			editNumber = true;
			break;
		case 1:
			droneDetector->reset();
			break;
	}
}

void Detectorsettings::buttonUp(){
	if(editNumber){
		int number = droneDetector->getScannPM();
		if(number == 1 ){
			number = 39;
		}else{
			number--;
		}
		droneDetector->setScannPM(number);
	}else{
		SubMenuList::buttonUp();
		/*if(this->activePoint == 0 ){
			this->activePoint= getNumberOfPoints()-1;
		}else{
			this->activePoint--;
		}*/
	}
}

void Detectorsettings::buttonDown(){
	if(editNumber){
		int number = droneDetector->getScannPM();
		number++;
		if(number>40){
			number = 1;
		}
		droneDetector->setScannPM(number);
	}else{
		SubMenuList::buttonDown();
		//activePoint++;
		//activePoint %=getNumberOfPoints();
	}
}

void Detectorsettings::buttonPrev(){
	if(editNumber){
		editNumber = false;
	}else{
		this->parent->acitvateMe();
	}
}