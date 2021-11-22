#include "Settings.h"

Settings::Settings(GUI* m):Menu("SETTINGS",m){
	scanSettings = new ScanSettings(this);
	gpsSettings = new GPSSettings(this); 
	sdcardsettings = new SDCardSettings(this);
	detectionSettings = new Detectorsettings(this);
	trakersettings = new TrackerSettings(this);
	speackerCheck = new SpeackerCheck(this);
}

void Settings::drawMenu(){
	drawPoint("Scanner");
	drawPoint("Detector Setting");
	drawPoint("Tracker Setting");
	drawPoint("GPS");
	drawPoint("SD-Card");
	drawPoint("SpeakerSettings");
}

void Settings::buttonNext(){
	switch (activeEntry){
		case 0:
			scanSettings->acitvateMe();
			break;

		case 1:
			detectionSettings->acitvateMe();
			break;

		case 2:
			trakersettings->acitvateMe();
			break;
		
		case 3:
			gpsSettings->acitvateMe();
			break;

		case 4:
			sdcardsettings->acitvateMe();
			break;

		case 5:
			speackerCheck->acitvateMe();
			break;
	}
}