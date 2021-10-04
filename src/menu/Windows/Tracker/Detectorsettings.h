#ifndef DETECTORSETTINGS_H
#define DETECTORSETTINGS_H

#include <Arduino.h>
#include "../../AbstractMenu.h"
#include "../../SubMenuList.h"
#include "../../../fpv/DroneDetector.h"
#include "../../../fpv/LapTracker.h"

class Detectorsettings : public SubMenuList{
	private:
		DroneDetector* detector;
		boolean editNumber;

	public:
		Detectorsettings(Adafruit_SSD1306* , AbstractMenu*, DroneDetector* detector);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif