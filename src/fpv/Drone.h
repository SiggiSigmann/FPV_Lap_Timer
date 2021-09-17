#ifndef Drone_H
#define Drone_H

#include <Arduino.h>
#include "../util/util.h"

#define RSSIVALUEBUFFER 48						//because this is the number wich can be displayed

class Drone{
	private:
		short freq =0;
		int noiselevel =0;
		int maxlevel =0;
		int values[RSSIVALUEBUFFER] = {0};			//last values

	public:
		Drone(){};

		byte getFreq();
		void setFreq(byte);

		int getNoiseLevel();
		void setNoiseLevel(int);

		int getMaxLevel();
		void setMaxLevel(int);

		void addRSSI(int);
		int* getRSSI();
};

#endif