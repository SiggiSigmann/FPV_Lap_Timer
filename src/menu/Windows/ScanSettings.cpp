#include "ScanSettings.h"

ScanSettings::ScanSettings(Adafruit_SSD1306* d, Menu* m, FPVScanner* sc):MenuPoint(d,m){
	this->sc = sc;
	tracker = new LapTracker();
}

void ScanSettings::draw(){
	this->display->setCursor(0,0);
	this->display->print("ScanSettings:");

	this->display->fillRect(4,18,116,8,BLACK);
	this->display->setCursor(18,18);
	this->display->drawRect(4,18,8,8,WHITE);
	this->display->print("Scan Noise");
	if(activePoint == 0){
		this->display->fillRect(4,18,8,8,WHITE);
	}

	this->display->fillRect(4,30,8,8,BLACK);
	this->display->setCursor(18,30);
	this->display->drawRect(4,30,8,8,WHITE);
	this->display->print("Clear Noise");
	if(activePoint == 1){
		this->display->fillRect(4,30,8,8,WHITE);
	}

	this->display->fillRect(4,42,116,8,BLACK);
	this->display->setCursor(18,42);
	this->display->print("MaxValue: ");
	this->display->print(sc->getMax());


	this->display->fillRect(4,54,116,8,BLACK);
	this->display->setCursor(18,54);
	this->display->print("Denoiced: ");
	this->display->print(sc->isDenoiced());

}

void ScanSettings::buttonNext(){
	switch (activePoint){
	case 0:
	this->display->setCursor(18,18);
	this->display->drawRect(4,18,8,8,WHITE);
	this->display->print("Scan Noise (run)");
	this->display->display();
		sc->captureNoise();
		break;
	
	case 1:
		sc->resetNoise();
		break;
	}
}

void ScanSettings::buttonUp(){
	if(this->activePoint ==0){
		this->activePoint= MENUENTRIES-1;
	}else{
		this->activePoint--;
	}
}

void ScanSettings::buttonDown(){
	this->activePoint++;
	this->activePoint %=MENUENTRIES;
}