#ifndef TRACKERSETTINGS_H
#define TRACKERSETTINGS_H

#include <Arduino.h>
#include "../../../AbstractMenu.h"
#include "../../../SubMenuList.h"
#include "../../../../fpv/LapTracker.h"

class TrackerSettings : public SubMenuList{
	private:
		LapTracker* tracker;
		boolean editUpper;
		boolean editLower;

	public:
		TrackerSettings(Adafruit_SSD1306* , AbstractMenu*, LapTracker* laptracker);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};


#endif