#ifndef DETECTORSETTINGS_H
#define DETECTORSETTINGS_H

#include <Arduino.h>
#include "../../Menu.h"

#include "../../../fpv/DroneDetector.h"

class Detectorsettings : public Menu{
	private:
		boolean editNumber;

	public:
		Detectorsettings(GUI*);
		void drawMenu();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif