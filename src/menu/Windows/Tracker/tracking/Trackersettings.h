#ifndef TRACKERSETTINGS_H
#define TRACKERSETTINGS_H

#include <Arduino.h>
#include "../../../Menu.h"
#include "../../../MenuList.h"
#include "../../../../fpv/LapTracker.h"

class TrackerSettings : public MenuList{
	private:
		LapTracker* tracker;
		boolean editUpper;
		boolean editLower;

	public:
		TrackerSettings(Adafruit_SSD1306* , Menu*, LapTracker* laptracker);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};


#endif