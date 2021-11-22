#ifndef TRACKERSETTINGS_H
#define TRACKERSETTINGS_H

#include <Arduino.h>
#include "../../Window.h"
#include "../../SubMenuList.h"
#include "../../../fpv/LapTracker.h"

class TrackerSettings : public SubMenuList{
	private:
		boolean editUpper = false;
		boolean editLower = false;

	public:
		TrackerSettings(Window*);
		void drawMenu();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};


#endif