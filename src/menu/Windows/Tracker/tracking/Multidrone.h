#ifndef MULTIDRONE_H
#define MULTIDRONE_H

#include <Arduino.h>
#include "../../../AbstractMenu.h"
#include "../../../MenuWindow.h"
#include "../../../../fpv/LapTracker.h"
#include "../../../../RX5808/channels.h"
#include "../../../../util/util.h"

class Multidrone : public MenuWindow{
	private:
		LapTracker* tracker;
		Scanner* sc;

		boolean showtimes = false;
	
	public:
		Multidrone( AbstractMenu*, Scanner*, LapTracker*);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void updateDrones();
};

#endif