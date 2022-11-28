#include "GPSSettings.h"


GPSSettings::GPSSettings():Menu("GPS SETTINGS"){
	gps->update();
	String date = gps->getDate();
	float pos[2] = {0};
	gps->getPosition(pos);

	this->addEntry(MenuEntry{"MinSat: " + String(gps->getMinSat()),2,0});
	this->addEntry(MenuEntry{"IsValid: " + String(gps->isValid()),1,0});
	this->addEntry(MenuEntry{"Sats: " + String(gps->getSatelites()),1,0});
	this->addEntry(MenuEntry{"LAT: " +  String(pos[0],10),1,0});
	this->addEntry(MenuEntry{"LNG: " +  String(pos[1],10),1,0});
	this->addEntry(MenuEntry{"SummerTime: " + String(gps->getSommerTime()),2,1});
	this->addEntry(MenuEntry{"TimeZone: "+String( gps->getTimeSzone()),2,2});
	this->addEntry(MenuEntry{gps->getTime() +" "+date.substring(0,6)+date.substring(8,10),1,0});
}

