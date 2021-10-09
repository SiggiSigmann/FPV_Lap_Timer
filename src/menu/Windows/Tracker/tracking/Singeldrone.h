#ifndef SINGLEDRONE_H
#define SINGLEDRONE_H

#include <Arduino.h>
#include "../../../AbstractMenu.h"
#include "../../../SubMenuList.h"
#include "../../../../fpv/LapTracker.h"
#include "../../../../fpv/Scanner.h"
#include "../../../../RX5808/channels.h"
#include "../../../../util/util.h"

class Singeldrone : public SubMenuList{
	private:
		LapTracker* tracker;
		Scanner* sc;

		byte i = 0;

		boolean windows = false;
	
	public:
		Singeldrone( AbstractMenu*,Scanner* , LapTracker* detector);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void updateDrones();
};

#endif