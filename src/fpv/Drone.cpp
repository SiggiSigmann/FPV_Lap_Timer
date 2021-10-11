#include "Drone.h"

/*Drone::Drone(int freq, int noiselevel, int maxlevel){
	this->freq = freq;
	this->noiselevel = noiselevel;
	this->maxlevel = maxlevel;
}*/


void Drone::setIndex(byte x){
	this->i = x;
}

byte Drone::getIndex(){
	return i;
}

int Drone::getFreq(){
	return pgm_read_word_near(channelFreqTable+pgm_read_word_near(channelList+i));
}

byte Drone::getChannel(){
	return pgm_read_word_near(channelNames+pgm_read_word_near(channelList+i));
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

	//update value
	setUpper(upper);
	setLower(lower);
}



void Drone::addRSSI(int x){
	//put values at the end of the value array and shift array
	insertAtEnd(values,x,RSSIVALUEBUFFER);

	if(maxlevel<x){
		setMaxLevel(x);
	}
}

int* Drone::getRSSI(){
	return values;
}

unsigned long Drone::getLastTime(){
	return millis() - lastTime;
}

void Drone::reset(){
	for(byte i=0; i<RSSIVALUEBUFFER; i++){
		values[i] = 0;
	}
}

int* Drone::getLaps(){
	return laps;
}

void Drone::addLap(byte i){
	int newTime =  millis() - lastTime;
	insertAtFront(laps, newTime, 4);

	if(newTime<bestLap) bestLap = newTime;

	lastTime =  millis();
	toneGenerator->playDrone(i);

	//logSD(i, newTime);
}


void Drone::setFareAway(boolean x ){
	faraway = x;
}

boolean Drone::getFareAway(){
	return faraway;
}

void Drone::setUpper(byte x ){
	upper = x;
	upperValue = (maxlevel*x) / 100;
}
int Drone::getUpper(){
	return upperValue;
}
void Drone::setLower(byte x){
	lower = x;
	lowerValue = (maxlevel*x) / 100;	
}
int Drone::getLower(){
	return lowerValue;
}

void Drone::resetTime(){
	for(byte i=0;i<4;i++){
		laps[i] = 0;
	}
	bestLap = 999999;
}

int Drone::getBest(){
	return bestLap;
}