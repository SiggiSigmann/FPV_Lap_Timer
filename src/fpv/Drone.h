#ifndef Drone_H
#define Drone_H

#include <Arduino.h>
#include "../util/util.h"
#include "../rx5808/channels.h"

#define RSSIVALUEBUFFER 48						//because this is the number which can be displayed

class Drone{
	private:
		byte i =0;
		int noiselevel =0;
		int maxlevel =0;
		int values[RSSIVALUEBUFFER] = {0};			//last values
		unsigned long lastTime=millis();
		int laps[4] = {0};

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
};

#endif