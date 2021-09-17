#include "Drone.h"

/*Drone::Drone(int freq, int noiselevel, int maxlevel){
	this->freq = freq;
	this->noiselevel = noiselevel;
	this->maxlevel = maxlevel;
}*/

short Drone::getFreq(){
	return freq;
}

int Drone::getNoiseLevel(){
	return noiselevel;
}

int Drone::getMaxLevel(){
	return maxlevel;
}

void Drone::setFreq(short x){
	this->freq = x;
	//Serial.println(x);
}
void Drone::setNoiseLevel(int x){
	this->noiselevel  = x;
}
void Drone::setMaxLevel(int x){
	this->maxlevel = x;
}

void Drone::addRSSI(int x){
	int temp = x;
	for(int i=47;i>=0;i--){
		int old = values[i];
		values[i] = temp;
		temp = old;
	}
}
int Drone::getRSSI(int x){
	return values[x];
}