#ifndef DETECTORSETTINGS_H
#define DETECTORSETTINGS_H

#include <Arduino.h>
#include "../../Menu.h"
#include "../../MenuList.h"
#include "../../../fpv/DroneDetector.h"
#include "../../../fpv/LapTracker.h"

class Detectorsettings : public MenuList{
	private:
		DroneDetector* detector;
		boolean editNumber;

	public:
		Detectorsettings(Adafruit_SSD1306* , Menu*, DroneDetector* detector);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif