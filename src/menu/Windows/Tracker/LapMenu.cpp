#include "LapMenu.h"

LapMenu::LapMenu(Adafruit_SSD1306* d, Menu* m, Scanner* sc):MenuList(d,m,3){
	//create Tracker
	LapTracker* tracker = new LapTracker();

	sfc = new ScanForDrones(d,this,sc,tracker);
	dt = new DroneTracker(d,this,sc,tracker);
	tr = new Trackersettings(d,this,tracker);
}

void LapMenu::draw(){
	//top
	this->display->setCursor(0,0);
	this->display->print("MENU - LAPTRACKER:");

	byte idx = 0;
	drawPoint(idx++,"Scann for Drones");
	drawPoint(idx++,"Start");
	drawPoint(idx++,"Tracker Settings");
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

