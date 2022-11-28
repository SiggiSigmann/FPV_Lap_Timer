#ifndef DRONETRACKER_H
#define DRONETRACKER_H

#include <Arduino.h>
#include "../../Menu.h"
#include "../../../fpv/Scanner.h"
#include "../../../fpv/DroneDetector.h"
#include "../../../fpv/LapTracker.h"
#include "../../../RX5808/channels.h"
#include "../../../util/util.h"
#include "tracking/Multidrone.h"
#include "tracking/Singeldrone.h"

class DroneTracker : public Menu{
	private:
		Multidrone* multi;
		Singeldrone* singel;

		boolean ok = false;
	
	public:
		DroneTracker(GUI*);
		void drawMenu();
		void buttonNext();

		void buttonPrev();
		void acitvateMe();
};

#endif