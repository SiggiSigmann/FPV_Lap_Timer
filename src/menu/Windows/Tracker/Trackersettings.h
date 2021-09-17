#ifndef TRACKERSETTINGS_H
#define TRACKERSETTINGS_H

#include <Arduino.h>
#include "../../Menu.h"
#include "../../MenuPoint.h"
#include "../../../fpv/LapTracker.h"

#define MENUENTRIES 2

class Trackersettings : public MenuPoint{
	private:
		int activePoint = 0;
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