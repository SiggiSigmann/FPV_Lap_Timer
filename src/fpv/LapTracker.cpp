#include "LapTracker.h"

void LapTracker::setMeasurements(int* level){
	measurevalues = level;
	short amount = CHANNELAMOUT;
	for(int i = 0; i< amount ;i++){
		int index = i;
		boolean peak = true;

		if(measurevalues[i]<this->strengthoffset) continue;
		
		for(int j = 0; j<scannPM; j++){
			if(--index < 0) break;
			if(measurevalues[i]<measurevalues[index]){
				peak = false;
				break;
			}
		}

		index = i;
		for(int j = 0; j<scannPM; j++){
			if(++index > CHANNELAMOUT-1) break;
			if(measurevalues[i]<measurevalues[index]){
				peak = false;
				break;
			}
		}


		if(peak){
			drones[numberOfDrones] = i;
			Serial.println(pgm_read_word_near(channelFreqTable +i));
			i += scannPM-1;
			numberOfDrones++;
			if(numberOfDrones == 10){
				return;
			}
		}
	}
}
short LapTracker::getNumberOfDrones(){
	return numberOfDrones;
}

byte* LapTracker::getDroneFreqs(){
	return drones;
}

void LapTracker::setMaxOffset(int m){
	strengthoffset = m;
}

void LapTracker::reset(){
	numberOfDrones = 0;
}

int LapTracker::getScannPM(){
	return this->scannPM;
}

void LapTracker::setScannPM(int x){
	this->scannPM = x;
}