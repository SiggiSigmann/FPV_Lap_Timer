#ifndef DRONETRACKER_H
#define DRONETRACKER_H

#include <Arduino.h>
#include "../../Menu.h"
#include "../../MenuList.h"
#include "../../../fpv/Scanner.h"
#include "../../../fpv/DroneDetector.h"
#include "../../../fpv/Drone.h"
#include "../../../RX5808/channels.h"
#include "../../../util/util.h"

class DroneTracker : public MenuList{
	private:
		Scanner* sc;
		DroneDetector* tracker;
		Drone* drones;

		int isx = 0;
		unsigned long last = millis();				//time till last update
	
	public:
		DroneTracker(Adafruit_SSD1306* , Menu*, Scanner* sc, DroneDetector* tracker);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif