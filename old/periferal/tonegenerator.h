#ifndef TONEGENERATOR_H
#define TONEGENERATOR_H

#include <arduino.h>
#include "../menu/pins.h"

class Tone{
	private:
		hw_timer_t * timer = NULL;
		boolean soundFlag = false;
		unsigned long timeToPlay = 0;

	public:
		Tone();
		void playDrone(byte);
		void play(int);
		void stop();
		void tickSound();
};

extern Tone* toneGenerator;

#endif