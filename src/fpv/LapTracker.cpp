#include "LapTracker.h"

int timeForOneScan = 0;

byte LapTracker::getNumberOfDrones(){
	return droneSize;
}

Drone* LapTracker::getDrones(){
	return drones;
}

void LapTracker::addDrone(byte i, int noise, int max){
	drones[droneSize].reset();
	drones[droneSize].setIndex(i);
	drones[droneSize].setNoiseLevel(noise);
	drones[droneSize].setMaxLevel(noise);
	drones[droneSize].setUpper(upperpercentage);
	drones[droneSize++].setLower(lowerpercentage);
}

void LapTracker::reset(){
	droneSize = 0;
}

void LapTracker::update(){
	for(byte i = 0; i<droneSize; i++){
		int val = scanner->scanIdx(drones[i].getIndex());
		drones[i].addRSSI(val);
		if(detectLap(i)){
			drones[i].addLap(i);

		}
	}
}

boolean LapTracker::detectLap(byte i){
	int amount = 20;

	if(drones[i].getFareAway()){
		int threshold = drones[i].getUpper();

		for(byte j = 0; j<amount;j++){
			if(drones[i].getRSSI()[(RSSIVALUEBUFFER-amount-1)+j] < threshold){
				return false;
			}
		}

		if(drones[i].getRSSI()[RSSIVALUEBUFFER-1] > threshold){
			return false;
		}
		drones[i].setFareAway(false);
		return true;
	}else{
		int threshold = drones[i].getLower();

		for(byte j = 0; j<amount;j++){
			if(drones[i].getRSSI()[(RSSIVALUEBUFFER-amount)+j] > threshold){
				return false;
			}
		}
		drones[i].setFareAway(true);
	}
	return false;
}

byte LapTracker::getUpper(){
	return upperpercentage;
}

void LapTracker::setUpper(byte x){
	upperpercentage = x;
	for(byte i = 0; i<droneSize; i++){
		drones[i].setUpper(upperpercentage);
	}
}

byte LapTracker::getLower(){
	return lowerpercentage;
}

void LapTracker::setLower(byte x){
	lowerpercentage = x;
	for(byte i = 0; i<droneSize; i++){
		drones[i].setLower(lowerpercentage);
	}
}

void LapTracker::resetTimes(){
	for(byte i = 0; i<droneSize; i++){
		drones[i].resetTime();
	}
}

void updateTracker(void * pvParameters ){
	unsigned long lastscannTime = millis();
	while(true){

		lapTracker->update();
		yield();					//let cpu do importent stuff
		timeForOneScan = millis()-lastscannTime;
		lastscannTime = millis();
	}

}

void LapTracker::startThread(){
	if( xHandle == NULL ) {
	xTaskCreate(updateTracker, "Scanner", 5000, NULL, 1, &xHandle );
	 }
}

void LapTracker::stopThread(){
	if( xHandle != NULL ) {
	vTaskDelete( xHandle );
	 }
}
