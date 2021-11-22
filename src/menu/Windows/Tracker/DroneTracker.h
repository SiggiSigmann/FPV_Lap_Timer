#ifndef DRONETRACKER_H
#define DRONETRACKER_H

#include <Arduino.h>
#include "../../Window.h"
#include "../../SubMenuList.h"
#include "../../../fpv/Scanner.h"
#include "../../../fpv/DroneDetector.h"
#include "../../../fpv/LapTracker.h"
#include "../../../RX5808/channels.h"
#include "../../../util/util.h"
#include "tracking/Multidrone.h"
#include "tracking/Singeldrone.h"

class DroneTracker : public SubMenuList{
	private:
		Multidrone* multi;
		Singeldrone* singel;

		boolean ok = false;
	
	public:
		DroneTracker(Window*);
		void drawMenu();
		void buttonNext();

		void buttonPrev();
		void acitvateMe();
};

#endif