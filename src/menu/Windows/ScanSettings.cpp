#include "ScanSettings.h"

ScanSettings::ScanSettings(Adafruit_SSD1306* d, Menu* m, Scanner* sc):MenuList(d,m,2){
	this->sc = sc;
}

void ScanSettings::draw(){
	//top
	this->display->setCursor(0,0);
	this->display->print("Scanner Settings:");

	byte idx = 0;
	drawPoint(idx++,"Scan Noise");
	drawPoint(idx++,"Clear Noise");
	drawInfo(idx++,"values: " + String(sc->getMaxNoise()) + " / " + String(sc->getMax()));
	drawInfo(idx++,"Denoise: " + String(sc->isDenoise()));
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