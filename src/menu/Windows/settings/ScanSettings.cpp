#include "ScanSettings.h"

ScanSettings::ScanSettings(Window* m):SubMenuList("SDCard SETTINGS",m){
}

void ScanSettings::drawMenu(){
	drawPoint("Scan Noise");
	drawPoint("Clear Noise");
	drawInfo("Values: " + String(scanner->getMaxNoise()) + " / " + String(scanner->getMax()));
	drawInfo("Denoise: " + String(scanner->isDenoise()));
}

void ScanSettings::buttonNext(){
	switch (activePoint){
		case 0:
			display.setCursor(18,18);
			display.drawRect(4,18,8,8,WHITE);
			display.print("Scan Noise (run)");
			display.display();
			scanner->captureNoise();
			break;
		
		case 1:
			scanner->resetNoise();
			break;
	}
}