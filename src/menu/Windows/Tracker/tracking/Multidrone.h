#ifndef MULTIDRONE_H
#define MULTIDRONE_H

#include <Arduino.h>
#include "../../../Menu.h"
#include "../../../MenuPoint.h"
#include "../../../../fpv/LapTracker.h"
#include "../../../../RX5808/channels.h"
#include "../../../../util/util.h"

class Multidrone : public MenuPoint{
	private:
		LapTracker* tracker;
		Scanner* sc;

		unsigned long last = millis();				//time till last update
		boolean showtimes = false;
	
	public:
		Multidrone(Adafruit_SSD1306* , Menu*, Scanner*, LapTracker*);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
};

#endif