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

void GPS::setTimeOffset(byte b){
	communication->getInt("gps.offset:"+String(b));
}

void GPS::update(){
	communication->flush();
}