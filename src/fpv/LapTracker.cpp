#include "LapTracker.h"

LapTracker::LapTracker(Scanner* sc){
	this->sc = sc;
}

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
	drones[droneSize++].setMaxLevel(max);
}

void LapTracker::reset(){
	droneSize = 0;
}

void LapTracker::update(){
	for(byte i = 0; i<droneSize; i++){
		int val = sc->scanIdx(drones[i].getIndex());
		drones[i].addRSSI(val);
		if(detectLap(i)){
			drones[i].addLap();
		}
	}
}

boolean LapTracker::detectLap(byte i){
	int threshold = drones[i].getThreshold();

	int amount = 20;

	if(drones[i].getFareAway()){

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
		for(byte j = 0; j<amount;j++){
			if(drones[i].getRSSI()[(RSSIVALUEBUFFER-amount)+j] > threshold/2){
				return false;
			}
		}
		drones[i].setFareAway(true);
	}
	return false;
}