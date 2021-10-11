#ifndef Drone_H
#define Drone_H

#include <Arduino.h>
#include "../util/util.h"
#include "../util/sdcard.h"
#include "../rx5808/channels.h"
#include "menu/pins.h"
#include "periferal/tonegenerator.h"


#define RSSIVALUEBUFFER 48						//because this is the number which can be displayed

class Drone{
	private:
		byte i =0;
		int noiselevel =0;
		int maxlevel =0;
		
		int values[RSSIVALUEBUFFER] = {0};			//last values
		unsigned long lastTime=millis();
		int laps[4] = {0};
		int bestLap = 999999;
		

		byte upper;
		byte lower;
		int upperValue = 0;
		int lowerValue = 0;
		boolean faraway = false;

	public:
		Drone(){};
		void reset();

		void setIndex(byte);
		byte getIndex();
		int getFreq();
		byte getChannel();


		int getNoiseLevel();
		void setNoiseLevel(int);

		int getMaxLevel();
		void setMaxLevel(int);

		void addRSSI(int);
		int* getRSSI();

		unsigned long getLastTime();

		int* getLaps();

		void addLap(byte i);

		void setFareAway(boolean);
		boolean getFareAway();

		void setUpper(byte);
		int getUpper();
		void setLower(byte);
		int getLower();

		void resetTime();

		int getBest();
};

#endif