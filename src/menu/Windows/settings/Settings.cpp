#include "Settings.h"

Settings::Settings(AbstractMenu* m):SubMenuList("SETTINGS",m){
	scanSettings = new ScanSettings(this);
	gpsSettings = new GPSSettings(this); 
	sdcardsettings = new SDCardSettings(this); 
}

void Settings::drawMenu(){
	drawPoint("Scanner");
	drawPoint("Detector Setting");
	drawPoint("Tracker Setting");
	drawPoint("GPS");
	drawPoint("SD-Card");

}

void Settings::buttonNext(){
	switch (activePoint){
		case 0:
			scanSettings->acitvateMe();
			break;
		
		case 3:
			gpsSettings->acitvateMe();
			break;

		case 4:
			sdcardsettings->acitvateMe();
			break;
	}
}