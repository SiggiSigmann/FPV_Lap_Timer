#ifndef SINGLEDRONE_H
#define SINGLEDRONE_H

#include <Arduino.h>
#include "../../../Menu.h"
#include "../../../../RX5808/channels.h"
#include "../../../../util/util.h"
#include "../../../../fpv/LapTracker.h"

class Singeldrone : public Menu{
	private:
		byte i = 0;

		boolean windows = false;
	
	public:
		Singeldrone(GUI*);
		void drawMenu();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void updateDrones();
};

#endif