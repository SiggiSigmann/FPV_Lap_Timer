#include "LapMenu.h"

LapMenu::LapMenu(Adafruit_SSD1306* d, Menu* m, FPVScanner* sc):MenuPoint(d,m){
	this->sc = sc;
	sfc = new ScanForDrones(d,this,sc);
}

void LapMenu::draw(){
	this->display->setCursor(0,0);
	this->display->print("MENU - LAPTRACKER:");

	this->display->fillRect(4,18,8,8,BLACK);
	this->display->setCursor(18,18);
	this->display->drawRect(4,18,8,8,WHITE);
	this->display->print("Scan Noise");
	if(activePoint == 0){
		this->display->fillRect(4,18,8,8,WHITE);
	}

	this->display->fillRect(4,30,8,8,BLACK);
	this->display->setCursor(18,30);
	this->display->drawRect(4,30,8,8,WHITE);
	this->display->print("Scann for Drones");
	if(activePoint == 1){
		this->display->fillRect(4,30,8,8,WHITE);
	}

	this->display->fillRect(4,42,8,8,BLACK);
	this->display->setCursor(18,42);
	this->display->drawRect(4,42,8,8,WHITE);
	this->display->print("Start");
	if(activePoint == 2){
		this->display->fillRect(4,42,8,8,WHITE);
	}

	this->display->fillRect(4,54,8,8,BLACK);
	this->display->setCursor(18,54);
	this->display->drawRect(4,54,8,8,WHITE);
	this->display->print("reset Noise");
	if(activePoint == 3){
		this->display->fillRect(4,54,8,8,WHITE);
	}
}	

void LapMenu::buttonNext(){
	switch (activePoint){
		case 0:
			display->clearDisplay();
			display->setCursor(0,0);
			display->print("capture Noise");
			display->display();
			sc->captureNoise();
			display->clearDisplay();
			break;
		case 1:
			sfc->acitvateMe();
			break;

		case 2:
			break;

		case 3:
			sc->resetNoise();
			break;
	}
}
void LapMenu::buttonUp(){
	if(this->activePoint ==0 ){this->activePoint= 3;}else{this->activePoint--;}
}
void LapMenu::buttonDown(){
	activePoint++;
	activePoint %=MENUENTRIES;
}
