#include "gps.h"

GPS::GPS(){
	Serial2.begin(9600);
}

void GPS::getPosition(float* loction){
	if(! gpsEncoder.location.isValid()){
		return ;
	}

	loction[0] = gpsEncoder.location.lat();
	loction[1] = gpsEncoder.location.lng();
}

byte GPS::getSatelites(){
	if(!gpsEncoder.satellites.isValid()) return 0;
	return gpsEncoder.satellites.value();
}

String GPS::getTime(){
	if(! gpsEncoder.time.isValid()) return "--:--:--";
	
	byte hour = gpsEncoder.time.hour()+ sommertime+timezone;
	timeoverfow = false;
	if(hour >= 24){
		hour -=24;
		timeoverfow= true;
	}

	return String(hour)+":"+String(gpsEncoder.time.minute())+":"+String(gpsEncoder.time.second());
}

String GPS::getDate(){
	if(! gpsEncoder.date.isValid()) return "--.--.----";

	byte day = gpsEncoder.date.day() +timeoverfow;

	return String(day)+"."+String(gpsEncoder.date.month())+"."+String(gpsEncoder.date.year());
}

void GPS::setTimeOffset(int b){
	timezone = b;
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