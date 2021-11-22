#ifndef SINGLEDRONE_H
#define SINGLEDRONE_H

#include <Arduino.h>
#include "../../../Window.h"
#include "../../../SubMenuList.h"
#include "../../../../RX5808/channels.h"
#include "../../../../util/util.h"
#include "../../../../fpv/LapTracker.h"

class Singeldrone : public SubMenuList{
	private:
		byte i = 0;

		boolean windows = false;
	
	public:
		Singeldrone( Window*);
		void drawMenu();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void updateDrones();
};

#endif