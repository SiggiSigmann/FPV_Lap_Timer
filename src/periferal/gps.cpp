#include "gps.h"

GPS::GPS(){}

float* GPS::getPosition(){
	return communication->getFloatArray2("gps.pos");
}

byte GPS::getSatelites(){
	return communication->getByte("gps.sat");
}

String GPS::getTime(){
	return communication->getString("gps.time");
}

String GPS::getDate(){
	return communication->getString("gps.date");
}

void GPS::setTimeOffset(int b){
	communication->getInt("gps.offset:"+String(b));
}

void GPS::update(){
	communication->flush();
}

boolean GPS::getSommerTime(){
	return this->sommertime;
}
void GPS::setSommerTime(boolean b){
	this->sommertime = b;
	int offsetToSend = timezone;
	if(sommertime) offsetToSend++; 
	communication->getByte("gps.offset:"+String((int)offsetToSend));
}

int GPS::getTimeSzone(){
	return timezone;
}
void GPS::setTimeSzone(int offset){
	this->timezone = offset;
	int offsetToSend = offset;
	if(sommertime) offsetToSend++; 
	communication->getByte("gps.offset:"+String(offsetToSend));
}

boolean GPS::isValid(){
	return (this->getSatelites()>=this->minSat);
}

byte GPS::getMinSat(){
	return this->minSat;
}

void GPS::setMinSat(byte sat){
	this->minSat = sat;
}