#ifndef SINGLEDRONE_H
#define SINGLEDRONE_H

#include <Arduino.h>
#include "../../../Menu.h"
#include "../../../MenuList.h"
#include "../../../../fpv/LapTracker.h"
#include "../../../../fpv/Scanner.h"
#include "../../../../RX5808/channels.h"
#include "../../../../util/util.h"

class Singeldrone : public MenuList{
	private:
		LapTracker* tracker;
		Scanner* sc;

		byte i = 0;
		unsigned long last = millis();				//time till last update

		boolean windows = false;
	
	public:
		Singeldrone(Adafruit_SSD1306* , Menu*,Scanner* , LapTracker* detector);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
};

#endif