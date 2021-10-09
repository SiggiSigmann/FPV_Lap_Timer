#ifndef SELECTION_H
#define SELECTION_H

#include "../AbstractMenu.h"
#include "../SubMenuList.h"
#include "../../RX5808/channels.h"
#include "tracker/LapMenu.h"
#include "settings/Settings.h"
#include "meter/Measuring.h"

#include "../../fpv/LapTracker.h"
#include "../../fpv/DroneDetector.h"


class Selection : public SubMenuList{
	private:
		LapMenu* lap;
		Measuring* meter;
		Settings* settings;

	public:
		Selection(AbstractMenu*);
		void drawMenu();
		void buttonNext();
};

#endif