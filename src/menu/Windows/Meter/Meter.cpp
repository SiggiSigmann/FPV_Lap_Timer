#include "Meter.h"

Meter::Meter(Adafruit_SSD1306* d, Menu* m, FPVScanner* sc):MenuPoint(d,m){
	osci = new Osciloskope(d, this, sc);
	rssi = new RSSIMeter(d, this, sc);
	this->sc = sc;
}

void Meter::draw(){
	this->display->setCursor(0,0);
	this->display->print("Meter:");

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

}	

void Meter::buttonNext(){
	switch (activePoint){
		case 0:
			osci->acitvateMe();
			break;
			
		case 1:
			rssi->acitvateMe();
			break;
	}
}

void Meter::buttonUp(){
	if(this->activePoint ==0){
		this->activePoint= MENUENTRIES-1;
	}else{
		this->activePoint--;
	}
}

void Meter::buttonDown(){
	this->activePoint++;
	this->activePoint %=MENUENTRIES;
}
