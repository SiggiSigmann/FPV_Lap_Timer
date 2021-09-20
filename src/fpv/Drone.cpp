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
	threshold = maxlevel*0.9;
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

void Drone::addLap(){
	int newTime =  millis() - lastTime;
	insertAtFront(laps, newTime, 4);

	lastTime =  millis();
	digitalWrite(1,1);
}

int Drone::getThreshold(){
	return threshold;
}