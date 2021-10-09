#include "GPSSettings.h"


GPSSettings::GPSSettings(AbstractMenu* m):SubMenuList("GPS SETTINGS",m){
}

void GPSSettings::drawMenu(){
	drawInfo("Sats: " + String(getSat()));
	drawInfo("LAT: " +  String(getLat()));
	drawInfo("LNG: " +  String(getLng()));
	drawInfo("" +  String(getDate()) + ":"+  String(getTime()));

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