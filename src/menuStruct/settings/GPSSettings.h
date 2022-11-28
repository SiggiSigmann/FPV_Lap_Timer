#ifndef GPSSETTINGS_H
#define GPSSETTINGS_H

#include "../../menu/ui/Menu.h"
#include "../../menu/ui/MenuEntry.h"
#include "../../periferal/gps.h"

class GPSSettings : public Menu{
	private:
		boolean editSommerTime=false;
		boolean editTimeSzone=false;
		boolean editinSat = false;
	public:
		GPSSettings();

		//actions before and after
		void preActions(){};
		void postActions(){};

		void buttonAction(byte){};
};

#endif