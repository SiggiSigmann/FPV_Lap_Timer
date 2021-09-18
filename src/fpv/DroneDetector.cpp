#include "DroneDetector.h"

void DroneDetector::setMeasurements(int* level){
	measurevalues = level;

	//itterate over all measurements
	for(byte i = 0; i< CHANNELAMOUT ;i++){
		//check if value is big enough
		Serial.println(String(measurevalues[i]) +" "+String(this->strengthoffset));
		if(measurevalues[i]<this->strengthoffset) continue;
		Serial.println("bigger");

		//asuem a peek in rssi is found
		boolean peak = true;

		//if values on the right are bigger
		byte index = i;
		for(byte j = 0; j<scannPM; j++){
			if(--index < 0) break;

			//check values
			if(measurevalues[i]<measurevalues[index]){
				peak = false;
				break;
			}
		}

		//if values on the left are bigger
		index = i;
		for(byte j = 0; j<scannPM; j++){
			if(++index > CHANNELAMOUT-1) break;

			//check values
			if(measurevalues[i]<measurevalues[index]){
				peak = false;
				break;
			}
		}

		//if peak is still a peal
		if(peak){
			//insert index
			drones[numberOfDrones++] = i;

			//set scannPM because this values don't need to be checked
			i += scannPM-1;

			//if max number of drones are detected stop
			if(numberOfDrones == MAXDRONENUMBER){
				return;
			}
		}
	}
}

short DroneDetector::getNumberOfDrones(){
	return numberOfDrones;
}

byte* DroneDetector::getDroneFreqs(){
	return drones;
}

void DroneDetector::setOffset(int m){
	strengthoffset = m;
}

void DroneDetector::reset(){
	numberOfDrones = 0;
}

int DroneDetector::getScannPM(){
	return this->scannPM;
}

void DroneDetector::setScannPM(int x){
	this->scannPM = x;
}