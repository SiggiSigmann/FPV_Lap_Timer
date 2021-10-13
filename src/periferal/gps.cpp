#include "gps.h"

GPS::GPS(){}

float* GPS::getPosition(){
	communication->getFloatArray2("gps.pos");
}

byte GPS::getSatelites(){
	communication->getFloatArray2("gps.sat");
}

String GPS::getTime(){
	communication->getString("gps.time");
}

String GPS::getDate(){
	communication->getString("gps.date");
}

void GPS::setTimeOffset(byte b){
	communication->getInt("gps.offset:"+String(b));
}

void GPS::update(){
}