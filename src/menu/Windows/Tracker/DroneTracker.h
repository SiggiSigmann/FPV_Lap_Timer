#ifndef DRONETRACKER_H
#define DRONETRACKER_H

#include <Arduino.h>
#include "../../AbstractMenu.h"
#include "../../SubMenuList.h"
#include "../../../fpv/Scanner.h"
#include "../../../fpv/DroneDetector.h"
#include "../../../fpv/LapTracker.h"
#include "../../../RX5808/channels.h"
#include "../../../util/util.h"
#include "tracking/Multidrone.h"
#include "tracking/Singeldrone.h"
#include "tracking/Trackersettings.h"
#include "../../../util/sdcard.h"

class DroneTracker : public SubMenuList{
	private:
		Scanner* sc;
		DroneDetector* detector;
		LapTracker* tracker;

		Multidrone* multi;
		Singeldrone* singel;
		TrackerSettings* trackersetings;

		boolean ok = false;
	
	public:
		DroneTracker(AbstractMenu*, Scanner* sc, DroneDetector* detector);
		void draw();
		void buttonNext();
};

#endif