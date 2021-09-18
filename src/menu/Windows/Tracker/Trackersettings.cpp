#include "Trackersettings.h"

Trackersettings::Trackersettings(Adafruit_SSD1306* d, Menu* m, DroneDetector* tracker):MenuList(d,m,2){
	this->tracker = tracker;
}

void Trackersettings::draw(){
	//top
	this->display->setCursor(0,0);
	this->display->print("Tracker Setting:");

	byte idx = 0;
	drawPoint(idx++,"ChannelsPM: " + String(this->tracker->getScannPM()));
	drawPoint(idx++,"reset");
	drawInfo(idx++ +1,"Detected Drones:"+String(this->tracker->getNumberOfDrones()));
}

void Trackersettings::buttonNext(){
	switch (activePoint){
		case 0:
			editNumber = true;
			break;
		case 1:
			this->tracker->reset();
			break;
	}
}

void Trackersettings::buttonUp(){
	if(editNumber){
		int number = this->tracker->getScannPM();
		if(number == 1 ){
			number = 39;
		}else{
			number--;
		}
		this->tracker->setScannPM(number);
	}else{
		if(this->activePoint == 0 ){
			this->activePoint= getNumberOfPoints()-1;
		}else{
			this->activePoint--;
		}
	}
}

void Trackersettings::buttonDown(){
	if(editNumber){
		int number = this->tracker->getScannPM();
		number++;
		if(number>40){
			number = 1;
		}
		this->tracker->setScannPM(number);
	}else{
		activePoint++;
		activePoint %=getNumberOfPoints();
	}
}

void Trackersettings::buttonPrev(){
	if(editNumber){
		editNumber = false;
	}else{
		this->parent->acitvateMe();
	}
}