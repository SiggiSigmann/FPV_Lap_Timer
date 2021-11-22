#ifndef LAPMENU_H
#define LAPMENU_H

#include "../../Menu.h"
#include "../../../RX5808/channels.h"
#include "ScanForDrones.h"
#include "DroneTracker.h"
#include "track/TrackMenu.h"

class LapMenu : public Menu{
	private:
		ScanForDrones* sfc;
		DroneTracker* dt;
		TrackMenu* tm;

	public:
		LapMenu(GUI*);
		void drawMenu();
		void buttonNext();
};

#endif