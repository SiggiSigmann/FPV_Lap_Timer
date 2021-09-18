#ifndef TRACKERSETTINGS_H
#define TRACKERSETTINGS_H

#include <Arduino.h>
#include "../../Menu.h"
#include "../../MenuList.h"
#include "../../../fpv/DroneDetector.h"
#include "../../../fpv/LapTracker.h"

class Trackersettings : public MenuList{
	private:
		DroneDetector* detector;
		boolean editNumber;

	public:
		Trackersettings(Adafruit_SSD1306* , Menu*, DroneDetector* detector);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif