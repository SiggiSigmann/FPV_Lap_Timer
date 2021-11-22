#ifndef DETECTORSETTINGS_H
#define DETECTORSETTINGS_H

#include <Arduino.h>
#include "../../Window.h"
#include "../../SubMenuList.h"

#include "../../../fpv/DroneDetector.h"

class Detectorsettings : public SubMenuList{
	private:
		boolean editNumber;

	public:
		Detectorsettings(Window*);
		void drawMenu();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif