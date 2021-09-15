#include "Selection.h"

Selection::Selection(Adafruit_SSD1306* d, Menu* m, FPVScanner* sc):MenuPoint(d,m){
	osci = new Osciloskope(d, this, sc);
	rssi = new RSSIMeter(d, this, sc);
	lap = new LapMenu(d, this, sc);
	scanSettngs = new ScanSettings(d, this, sc);
	this->scan = sc;
}

void Selection::draw(){
	this->display->setCursor(0,0);
	this->display->print("MENU:");

	this->display->fillRect(4,18,8,8,BLACK);
	this->display->setCursor(18,18);
	this->display->drawRect(4,18,8,8,WHITE);
	this->display->print("OSCI");
	if(activePoint == 0){
		this->display->fillRect(4,18,8,8,WHITE);
	}

	this->display->fillRect(4,30,8,8,BLACK);
	this->display->setCursor(18,30);
	this->display->drawRect(4,30,8,8,WHITE);
	this->display->print("RSSI");
	if(activePoint == 1){
		this->display->fillRect(4,30,8,8,WHITE);
	}

	this->display->fillRect(4,42,8,8,BLACK);
	this->display->setCursor(18,42);
	this->display->drawRect(4,42,8,8,WHITE);
	this->display->print("LAPTRACKER");
	if(activePoint == 2){
		this->display->fillRect(4,42,8,8,WHITE);
	}

	this->display->fillRect(4,54,8,8,BLACK);
	this->display->setCursor(18,54);
	this->display->drawRect(4,54,8,8,WHITE);
	this->display->print("Scanner Settings");
	if(activePoint == 3){
		this->display->fillRect(4,54,8,8,WHITE);
	}
}	

void Selection::buttonNext(){
	switch (activePoint){
		case 0:
			osci->acitvateMe();
			break;
			
		case 1:
			rssi->acitvateMe();
			break;

		case 2:
			lap->acitvateMe();
			break;

		case 3:
			scanSettngs->acitvateMe();
			break;
	}
}

void Selection::buttonUp(){
	if(this->activePoint ==0){
		this->activePoint= MENUENTRIES-1;
	}else{
		this->activePoint--;
	}
}

void Selection::buttonDown(){
	this->activePoint++;
	this->activePoint %=MENUENTRIES;
}
