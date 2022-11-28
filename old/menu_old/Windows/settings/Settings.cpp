#include "Settings.h"

Settings::Settings(GUI* m):Menu("SETTINGS",m){
	scanSettings = new ScanSettings(this);
	gpsSettings = new GPSSettings(this); 
	detectionSettings = new Detectorsettings(this);
	trakersettings = new TrackerSettings(this);
	sdSettings = new SDSettings(this);
	speackerCheck = new SpeackerCheck(this);
	toastSettings = new ToastSettings(this);
	dhtSettings = new DHTSettings(this);
}

void Settings::drawMenu(){
	drawPoint("Scanner");
	drawPoint("Detector Setting");
	drawPoint("Tracker Setting");
	drawPoint("GPS");
	drawPoint("SD Settings");
	drawPoint("SpeakerSettings");
	drawPoint("Toast Settings");
	drawPoint("DHT Settings");
	drawInfo();
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
			sdSettings->acitvateMe();
			break;

		case 5:
			speackerCheck->acitvateMe();
			break;
		
		case 6:
			toastSettings->acitvateMe();
			break;

		case 7:
			dhtSettings->acitvateMe();
			break;
	}
}

void Settings::preActions(){
	settingsManager->loadSettings();
}

void Settings::postActions(){
	settingsManager->storeSettings();
}
