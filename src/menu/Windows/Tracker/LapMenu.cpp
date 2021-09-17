#include "LapMenu.h"

LapMenu::LapMenu(Adafruit_SSD1306* d, Menu* m, FPVScanner* sc):MenuPoint(d,m){
	this->sc = sc;
	LapTracker* tracker = new LapTracker();
	sfc = new ScanForDrones(d,this,sc,tracker);
	dt = new DroneTracker(d,this,sc,tracker);
	tr = new Trackersettings(d,this,tracker);
}

void LapMenu::draw(){
	this->display->setCursor(0,0);
	this->display->print("MENU - LAPTRACKER:");

	this->display->fillRect(4,18,8,8,BLACK);
	this->display->setCursor(18,18);
	this->display->drawRect(4,18,8,8,WHITE);
	this->display->print("Scann for Drones");
	if(activePoint == 0){
		this->display->fillRect(4,18,8,8,WHITE);
	}

	this->display->fillRect(4,30,8,8,BLACK);
	this->display->setCursor(18,30);
	this->display->drawRect(4,30,8,8,WHITE);
	this->display->print("Start");
	if(activePoint == 1){
		this->display->fillRect(4,30,8,8,WHITE);
	}

	this->display->fillRect(4,42,8,8,BLACK);
	this->display->setCursor(18,42);
	this->display->drawRect(4,42,8,8,WHITE);
	this->display->print("Trackersettings");
	if(activePoint == 2){
		this->display->fillRect(4,42,8,8,WHITE);
	}
}	

void LapMenu::buttonNext(){
	switch (activePoint){
		case 0:
			sfc->acitvateMe();
			break;
		case 1:
			dt->acitvateMe();
			break;
		case 2:
			tr->acitvateMe();
			break;
	}
}
void LapMenu::buttonUp(){
	if(this->activePoint ==0 ){this->activePoint= MENUENTRIES-1;}else{this->activePoint--;}
}
void LapMenu::buttonDown(){
	activePoint++;
	activePoint %=MENUENTRIES;
}
