#include "gps.h"

TinyGPSPlus gpsDB220;

void setupGPS(){
	Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
	gpsDB220 = TinyGPSPlus();
}

void updateGPS(){
	while (Serial2.available() > 0) gpsDB220.encode(Serial2.read());
}

float getLat(){
	if(gpsDB220.location.isValid()) return gpsDB220.location.lat();
	return 0;
}

float getLng(){
	if(gpsDB220.location.isValid()) return gpsDB220.location.lng();
	return 0;
}

byte getSat(){
	if(gpsDB220.satellites.isValid()) return gpsDB220.satellites.value();
	return 0;
}

uint getTime(){
	if(gpsDB220.time.isValid()) return gpsDB220.time.value();
	return 0;
}

uint getDate(){
	if(gpsDB220.date.isValid()) return gpsDB220.date.value();
	return 0;
}