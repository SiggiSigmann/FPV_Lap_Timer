#ifndef TRACKERSETTINGS_H
#define TRACKERSETTINGS_H

#include <Arduino.h>
#include "../../AbstractMenu.h"
#include "../../SubMenuList.h"

class TrackerSettings : public SubMenuList{
	private:
		boolean editUpper = false;
		boolean editLower = false;

	public:
		TrackerSettings(AbstractMenu*);
		void drawMenu();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};


#endif