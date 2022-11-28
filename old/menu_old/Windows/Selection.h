#ifndef SELECTION_H
#define SELECTION_H

#include "../Menu.h"
#include "tracker/LapMenu.h"
#include "settings/Settings.h"
#include "meter/Measuring.h"


class Selection : public Menu{
	private:
		LapMenu* lap;
		Measuring* meter;
		Settings* settings;

	public:
		Selection(GUI*);
		void drawMenu();
		void buttonNext();
};

#endif