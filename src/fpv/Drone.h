#ifndef Drone_H
#define Drone_H

#include <Arduino.h>

class Drone{
	private:
		short freq =0;
		int noiselevel =0;
		int maxlevel =0;
		int values[48] = {0};

	public:
		Drone(){};
		//Drone(int freq, int noiselevel, int maxlevel);
		short getFreq();
		int getNoiseLevel();
		int getMaxLevel();
		void setFreq(short);
		void setNoiseLevel(int);
		void setMaxLevel(int);
		void addRSSI(int);
		int getRSSI(int);
};

#endif