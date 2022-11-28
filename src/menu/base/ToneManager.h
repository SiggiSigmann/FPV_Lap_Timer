#ifndef TONEGENERATOR_H
#define TONEGENERATOR_H

#include <Arduino.h>
#include "../periferals/pins.h"

class ToneManager{
	private:
		hw_timer_t* timer = NULL;
		boolean soundFlag = false;
		unsigned long timeToPlay = 0;

	public:
		ToneManager();
		void playDrone(byte);
		void play(int);
		void stop();
		void tickSound();
};

extern ToneManager* toneManager;

#endif