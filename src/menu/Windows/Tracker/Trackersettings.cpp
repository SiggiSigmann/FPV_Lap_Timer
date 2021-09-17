#include "Trackersettings.h"

Trackersettings::Trackersettings(Adafruit_SSD1306* d, Menu* m, LapTracker* tracker):MenuPoint(d,m){
	this->tracker = tracker;
}

void Trackersettings::draw(){
	this->display->setCursor(0,0);
	this->display->print("Settings - LAPTRACKER:");

	this->display->fillRect(4,18,100,8,BLACK);
	this->display->setCursor(18,18);
	this->display->drawRect(4,18,8,8,WHITE);
	this->display->print("ChannelsPM: ");
	this->display->print(this->tracker->getScannPM());
	if(activePoint == 0){
		this->display->fillRect(4,18,8,8,WHITE);
	}

	this->display->fillRect(4,30,100,8,BLACK);
	this->display->setCursor(18,30);
	this->display->drawRect(4,30,8,8,WHITE);
	this->display->print("reset");
	if(activePoint == 1){
		this->display->fillRect(4,30,8,8,WHITE);
	}

	this->display->fillRect(4,54,116,8,BLACK);
	this->display->setCursor(18,54);
	this->display->print("Detected Drones:");
	this->display->print(this->tracker->getNumberOfDrones());
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
			this->activePoint= MENUENTRIES-1;
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
		activePoint %=MENUENTRIES;
	}
}

void Trackersettings::buttonPrev(){
	if(editNumber){
		editNumber = false;
	}else{
		this->parent->acitvateMe();
	}
}