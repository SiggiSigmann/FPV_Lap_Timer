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

void LapTracker::addDrone(int freq, int noise, int max){
	drones[droneSize].reset();
	drones[droneSize].setFreq(freq);
	drones[droneSize].setNoiseLevel(noise);
	drones[droneSize++].setMaxLevel(max);
}

void LapTracker::reset(){
	droneSize = 0;
}

void LapTracker::update(){
	for(byte i = 0; i<droneSize; i++){
		int val = sc->scanFreq(drones[i].getFreq());
		drones[i].addRSSI(val);
	}
}