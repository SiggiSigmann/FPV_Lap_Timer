#include "ScanSettings.h"

ScanSettings::ScanSettings(AbstractMenu* m, Scanner* sc):SubMenuList("SDCard SETTINGS",m){
	this->sc = sc;
}

void ScanSettings::drawMenu(){
	drawPoint("Scan Noise");
	drawPoint("Clear Noise");
	drawInfo("Values: " + String(sc->getMaxNoise()) + " / " + String(sc->getMax()));
	drawInfo("Denoise: " + String(sc->isDenoise()));
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