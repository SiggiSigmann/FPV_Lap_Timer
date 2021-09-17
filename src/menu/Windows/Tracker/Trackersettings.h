#ifndef TRACKERSETTINGS_H
#define TRACKERSETTINGS_H

#include <Arduino.h>
#include "../../Menu.h"
#include "../../MenuList.h"
#include "../../../fpv/LapTracker.h"

class Trackersettings : public MenuList{
	private:
		LapTracker* tracker;
		boolean editNumber;

	public:
		Trackersettings(Adafruit_SSD1306* , Menu*, LapTracker* tracker);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif