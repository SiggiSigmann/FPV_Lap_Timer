#include "Settings.h"

Settings::Settings(AbstractMenu* m, Scanner* sc):SubMenuList("SETTINGS",m){
	scanSettings = new ScanSettings(this, sc);
	gpsSettings = new GPSSettings(this); 
	sdcardsettings = new SDCardSettings(this); 
}

void Settings::drawMenu(){
	drawPoint("Scanner");
	drawPoint("GPS");
	drawPoint("SD-Card");
}

void Settings::buttonNext(){
	switch (activePoint){
		case 0:
			scanSettings->acitvateMe();
			break;
		
		case 1:
			gpsSettings->acitvateMe();
			break;

		case 2:
			sdcardsettings->acitvateMe();
			break;
	}
}