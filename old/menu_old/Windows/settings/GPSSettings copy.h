#ifndef GPSSETTINGS_H
#define GPSSETTINGS_H

#include "../../Menu.h"
#include "../../../periferal/gps.h"

class GPSSettings : public Menu{
	private:
		boolean editSommerTime=false;
		boolean editTimeSzone=false;
		boolean editinSat = false;
	public:
		GPSSettings(GUI*);
		void drawMenu();
		void buttonNext();
		void buttonPrev();
		void buttonUp();
		void buttonDown();
};

#endif