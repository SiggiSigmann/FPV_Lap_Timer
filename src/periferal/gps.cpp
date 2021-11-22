#include "gps.h"

GPS::GPS(){
	Serial2.begin(9600);
}

float* GPS::getPosition(){
	
}

byte GPS::getSatelites(){
	if(!gpsEncoder.satellites.isValid()) return 0;
	return gpsEncoder.satellites.value();
}

String GPS::getTime(){

}

String GPS::getDate(){
	
}

void GPS::setTimeOffset(int b){
	
}

void GPS::update(){
	while (Serial2.available() > 0)
  		gpsEncoder.encode(Serial2.read());
}

boolean GPS::getSommerTime(){
	return sommertime;
}
void GPS::setSommerTime(boolean b){
	sommertime  = b;
}

int GPS::getTimeSzone(){
	return timezone;
}

void GPS::setTimeSzone(int offset){
	timezone = offset;
}

boolean GPS::isValid(){
	if(getSatelites()>=minSat){
		return true;
	}
	return false;
}

byte GPS::getMinSat(){
	return minSat;
}

void GPS::setMinSat(byte sat){
	minSat = sat;
}