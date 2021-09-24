#include "Settings.h"

Settings::Settings(Adafruit_SSD1306* d, Menu* m, Scanner* sc):MenuList(d,m,3){
	scanSettings = new ScanSettings(d, this, sc);
	gpsSettings = new GPSSettings(d, this); 
	sdcardsettings = new SDCardSettings(d, this); 
}

void Settings::draw(){
	//top
	this->display->setCursor(0,0);
	this->display->print("SETTINGS:");

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