#ifndef GPSSETTINGS_H
#define GPSSETTINGS_H

#include "../../AbstractMenu.h"
#include "../../SubMenuList.h"
#include "../../../periferal/gps.h"

class GPSSettings : public SubMenuList{
	private:
		boolean editSommerTime=false;
		boolean editTimeSzone=false;
		boolean editinSat = false;
	public:
		GPSSettings(AbstractMenu*);
		void drawMenu();
		void buttonNext();
		void buttonPrev();
		void buttonUp();
		void buttonDown();
};

#endif