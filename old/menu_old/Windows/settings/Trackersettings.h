#ifndef TRACKERSETTINGS_H
#define TRACKERSETTINGS_H

#include <Arduino.h>
#include "../../Menu.h"
#include "../../../fpv/LapTracker.h"

class TrackerSettings : public Menu{
	private:
		boolean editUpper = false;
		boolean editLower = false;

	public:
		TrackerSettings(GUI*);
		void drawMenu();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};


#endif