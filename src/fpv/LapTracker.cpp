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
	}
}