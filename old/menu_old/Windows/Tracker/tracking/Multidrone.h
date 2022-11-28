#ifndef MULTIDRONE_H
#define MULTIDRONE_H

#include <Arduino.h>
#include "../../../Frame.h"
#include "../../../../RX5808/channels.h"
#include "../../../../util/util.h"
#include "../../../../fpv/LapTracker.h"

class Multidrone : public Frame{
	private:
		boolean showtimes = false;
	
	public:
		Multidrone(GUI*);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void updateDrones();
};

#endif