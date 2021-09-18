#include "Drone.h"

/*Drone::Drone(int freq, int noiselevel, int maxlevel){
	this->freq = freq;
	this->noiselevel = noiselevel;
	this->maxlevel = maxlevel;
}*/

int Drone::getFreq(){
	return freq;
}

void Drone::setFreq(int x){
	this->freq = x;

}


int Drone::getNoiseLevel(){
	return noiselevel;
}

void Drone::setNoiseLevel(int x){
	this->noiselevel  = x;
}


int Drone::getMaxLevel(){
	return maxlevel;
}

void Drone::setMaxLevel(int x){
	this->maxlevel = x;
}



void Drone::addRSSI(int x){
	//put values at the end of the value array and shift array
	insertAtEnd(values,x,RSSIVALUEBUFFER);

	if(maxlevel<x){
		maxlevel = x;
	}
}

int* Drone::getRSSI(){
	return values;
}

unsigned long Drone::getLastTime(){
	return millis() - lastTime;
}

void Drone::reset(){
	for(byte i; i<RSSIVALUEBUFFER; i++){
		values[i] = 0;
	}
}