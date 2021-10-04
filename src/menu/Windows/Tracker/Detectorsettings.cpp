#include "Detectorsettings.h"

Detectorsettings::Detectorsettings(Adafruit_SSD1306* d, AbstractMenu* m, DroneDetector* detector):SubMenuList(d,m,2){
	this->detector = detector;
}

void Detectorsettings::draw(){
	//top
	this->display->setCursor(0,0);
	this->display->print("DETECTOR SETTINGS:");

	byte idx = 0;
	drawPoint(idx++,"ChannelsPM: " + String(this->detector->getScannPM()));
	drawPoint(idx++,"Reset");
	drawInfo(idx++ +1,"Detected Drones:"+String(this->detector->getNumberOfDrones()));
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
		if(this->activePoint == 0 ){
			this->activePoint= getNumberOfPoints()-1;
		}else{
			this->activePoint--;
		}
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
		activePoint++;
		activePoint %=getNumberOfPoints();
	}
}

void Detectorsettings::buttonPrev(){
	if(editNumber){
		editNumber = false;
	}else{
		this->parent->acitvateMe();
	}
}