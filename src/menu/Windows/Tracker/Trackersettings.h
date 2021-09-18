#ifndef TRACKERSETTINGS_H
#define TRACKERSETTINGS_H

#include <Arduino.h>
#include "../../Menu.h"
#include "../../MenuList.h"
#include "../../../fpv/DroneDetector.h"

class Trackersettings : public MenuList{
	private:
		DroneDetector* tracker;
		boolean editNumber;

	public:
		Trackersettings(Adafruit_SSD1306* , Menu*, DroneDetector* tracker);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif