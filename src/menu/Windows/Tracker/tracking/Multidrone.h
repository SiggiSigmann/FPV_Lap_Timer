#ifndef MULTIDRONE_H
#define MULTIDRONE_H

#include <Arduino.h>
#include "../../../Window.h"
#include "../../../MenuWindow.h"
#include "../../../../RX5808/channels.h"
#include "../../../../util/util.h"
#include "../../../../fpv/LapTracker.h"

class Multidrone : public MenuWindow{
	private:
		boolean showtimes = false;
	
	public:
		Multidrone( Window*);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void updateDrones();
};

#endif