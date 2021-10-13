#include "GPSSettings.h"


GPSSettings::GPSSettings(AbstractMenu* m):SubMenuList("GPS SETTINGS",m){
}

void GPSSettings::drawMenu(){
	gps->update();

	drawInfo("Sats: " + String(gps->getSatelites()));
	float* pos = gps->getPosition();
	drawInfo("LAT: " +  String(pos[0]));
	drawInfo("LNG: " +  String(pos[1]));
	String date = gps->getDate();
	drawInfo(gps->getTime() +" "+date.substring(0,6)+date.substring(8,10));


}

void GPSSettings::buttonNext(){
	switch (activePoint){
		case 0:
			break;
		
		case 1:
			break;
	}
}