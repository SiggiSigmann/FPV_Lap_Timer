#ifndef DRONETRACKER_H
#define DRONETRACKER_H

#include <Arduino.h>
#include "../../Menu.h"
#include "../../MenuPoint.h"
#include "../../../fpv/Scanner.h"
#include "../../../fpv/LapTracker.h"
#include "../../../fpv/Drone.h"
#include "../../../RX5808/channels.h"

#define MENUENTRIES 1

class DroneTracker : public MenuPoint{
	private:
		int activePoint = 0;
		FPVScanner* sc;
		LapTracker* tracker;
		Drone* drones;
		int isx = 0;
		bool exists = 0;
		unsigned long last = millis();

	public:
		DroneTracker(Adafruit_SSD1306* , Menu*, FPVScanner* sc, LapTracker* tracker);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif