#ifndef DRONETRACKER_H
#define DRONETRACKER_H

#include <Arduino.h>
#include "../../Menu.h"
#include "../../MenuList.h"
#include "../../../fpv/Scanner.h"
#include "../../../fpv/DroneDetector.h"
#include "../../../fpv/LapTracker.h"
#include "../../../RX5808/channels.h"
#include "../../../util/util.h"
#include "tracking/Multidrone.h"
#include "tracking/Singeldrone.h"

class DroneTracker : public MenuList{
	private:
		Scanner* sc;
		DroneDetector* detector;
		LapTracker* tracker;

		Multidrone* multi;
		Singeldrone* singel;

		unsigned long last = millis();				//time till last update
		boolean ok = false;
	
	public:
		DroneTracker(Adafruit_SSD1306* , Menu*, Scanner* sc, DroneDetector* detector);
		void draw();
		void buttonNext();
};

#endif