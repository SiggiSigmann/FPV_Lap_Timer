#ifndef LAPMENU_H
#define LAPMENU_H

#include "../../Window.h"
#include "../../SubMenuList.h"
#include "../../../RX5808/channels.h"
#include "ScanForDrones.h"
#include "DroneTracker.h"
#include "track/TrackMenu.h"

class LapMenu : public SubMenuList{
	private:
		ScanForDrones* sfc;
		DroneTracker* dt;
		TrackMenu* tm;

	public:
		LapMenu(Window*);
		void drawMenu();
		void buttonNext();
};

#endif