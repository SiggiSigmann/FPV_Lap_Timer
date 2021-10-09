#include "Detectorsettings.h"

Detectorsettings::Detectorsettings(AbstractMenu* m, DroneDetector* detector):SubMenuList("DETECTOR SETTINGS",m){
	this->detector = detector;
}

void Detectorsettings::drawMenu(){
	drawPoint("ChannelsPM: " + String(this->detector->getScannPM()));
	drawPoint("Reset");
	drawInfo("");
	drawInfo("Detected Drones:"+String(this->detector->getNumberOfDrones()));
}

void Detectorsettings::buttonNext(){
	switch (activePoint){
		case 0:
			editNumber = true;
			break;
		case 1:
			this->detector->reset();
			break;
	}
}

void Detectorsettings::buttonUp(){
	if(editNumber){
		int number = this->detector->getScannPM();
		if(number == 1 ){
			number = 39;
		}else{
			number--;
		}
		this->detector->setScannPM(number);
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
		int number = this->detector->getScannPM();
		number++;
		if(number>40){
			number = 1;
		}
		this->detector->setScannPM(number);
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