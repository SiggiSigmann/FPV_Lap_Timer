#ifndef LAPMENU_H
#define LAPMENU_H

#include "../../AbstractMenu.h"
#include "../../SubMenuList.h"
#include "../../../fpv/Scanner.h"
#include "../../../fpv/TrackManager.h"
#include "../../../RX5808/channels.h"
#include "ScanForDrones.h"
#include "DroneTracker.h"
#include "Detectorsettings.h"
#include "track/TrackMenu.h"

class LapMenu : public SubMenuList{
	private:
		ScanForDrones* sfc;
		DroneTracker* dt;
		Detectorsettings* tr;
		TrackMenu* tm;

	public:
		LapMenu(AbstractMenu*, Scanner* sc);
		void draw();
		void buttonNext();
};

#endif