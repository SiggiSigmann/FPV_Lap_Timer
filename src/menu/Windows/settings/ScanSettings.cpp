#include "ScanSettings.h"

ScanSettings::ScanSettings(AbstractMenu* m, Scanner* sc):SubMenuList("SDCard SETTINGS",m,2){
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
			display.setCursor(18,18);
			display.drawRect(4,18,8,8,WHITE);
			display.print("Scan Noise (run)");
			display.display();
			sc->captureNoise();
			break;
		
		case 1:
			sc->resetNoise();
			break;
	}
}