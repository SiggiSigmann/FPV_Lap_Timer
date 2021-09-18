#ifndef SINGLEDRONE_H
#define SINGLEDRONE_H

#include <Arduino.h>
#include "../../../Menu.h"
#include "../../../MenuPoint.h"
#include "../../../../fpv/LapTracker.h"
#include "../../../../fpv/Scanner.h"
#include "../../../../RX5808/channels.h"
#include "../../../../util/util.h"

class Singeldrone : public MenuPoint{
	private:
		LapTracker* tracker;
		Scanner* sc;

		unsigned long last = millis();				//time till last update
	
	public:
		Singeldrone(Adafruit_SSD1306* , Menu*,Scanner* , LapTracker* detector);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
};

#endif