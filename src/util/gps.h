#include <TinyGPS++.h>

#define RXD2 16
#define TXD2 17

TinyGPSPlus gps;

void setupGPS(){
	Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
	gps = TinyGPSPlus();
}

void updateGPS(){
	while (Serial2.available() > 0) gps.encode(Serial2.read());
}

float getLat(){
	if(gps.location.isValid()) return gps.location.lat();
	return 0;
}

float getLng(){
	if(gps.location.isValid()) return gps.location.lng();
	return 0;
}

byte getSat(){
	if(gps.satellites.isValid()) return gps.satellites.value();
	return 0;
}

uint getTime(){
	if(gps.time.isValid()) return gps.time.value();
	return 0;
}

uint getDate(){
	if(gps.date.isValid()) return gps.date.value();
	return 0;
}