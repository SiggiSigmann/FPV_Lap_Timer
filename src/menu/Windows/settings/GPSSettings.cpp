#include "GPSSettings.h"


GPSSettings::GPSSettings(Adafruit_SSD1306* d, Menu* m):MenuList(d,m,0){
}

void GPSSettings::draw(){
	//top
	this->display->setCursor(0,0);
	this->display->print("GPS SETTINGS:");

	byte idx = 0;
	drawInfo(idx++,"Sats: " + String(getSat()));
	drawInfo(idx++,"LAT: " +  String(getLat()));
	drawInfo(idx++,"LNG: " +  String(getLng()));
	drawInfo(idx++,"" +  String(getDate()) + ":"+  String(getTime()));

	//update gps
	updateGPS();
}

void GPSSettings::buttonNext(){
	switch (activePoint){
		case 0:
			break;
		
		case 1:
			break;
	}
}