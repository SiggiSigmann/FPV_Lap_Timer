#include "ScanSettings.h"

ScanSettings::ScanSettings(Adafruit_SSD1306* d, AbstractMenu* m, Scanner* sc):SubMenuList("SDCard SETTINGS",d,m,2){
	this->sc = sc;
}

void ScanSettings::draw(){
	byte idx = 0;
	drawPoint(idx++,"Scan Noise");
	drawPoint(idx++,"Clear Noise");
	drawInfo(idx++,"Values: " + String(sc->getMaxNoise()) + " / " + String(sc->getMax()));
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