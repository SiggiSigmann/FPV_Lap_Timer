#include "Settings.h"

Settings::Settings(AbstractMenu* m, Scanner* sc):SubMenuList("SETTINGS",m,3){
	scanSettings = new ScanSettings(this, sc);
	gpsSettings = new GPSSettings(this); 
	sdcardsettings = new SDCardSettings(this); 
}

void Settings::draw(){
	byte idx = 0;
	drawPoint(idx++,"Scanner");
	drawPoint(idx++,"GPS");
	drawPoint(idx++,"SD-Card");
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