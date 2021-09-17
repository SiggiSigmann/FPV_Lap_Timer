#ifndef DRONETRACKER_H
#define DRONETRACKER_H

#include <Arduino.h>
#include "../../Menu.h"
#include "../../MenuPoint.h"
#include "../../../fpv/Scanner.h"
#include "../../../fpv/LapTracker.h"
#include "../../../fpv/Drone.h"
#include "../../../RX5808/channels.h"
#include "../../../util/util.h"

class DroneTracker : public MenuPoint{
	private:
		Scanner* sc;
		LapTracker* tracker;
		Drone* drones;
		int isx = 0;
		bool exists = 0;
		unsigned long last = millis();				//time till last update

	public:
		DroneTracker(Adafruit_SSD1306* , Menu*, Scanner* sc, LapTracker* tracker);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif