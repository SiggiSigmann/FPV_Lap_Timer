#include "Settings.h"

Settings::Settings(Adafruit_SSD1306* d, AbstractMenu* m, Scanner* sc):SubMenuList("SETTINGS",d,m,3){
	scanSettings = new ScanSettings(d, this, sc);
	gpsSettings = new GPSSettings(d, this); 
	sdcardsettings = new SDCardSettings(d, this); 
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