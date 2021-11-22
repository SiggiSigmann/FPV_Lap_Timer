#ifndef SELECTION_H
#define SELECTION_H

#include "../SubMenuList.h"
#include "tracker/LapMenu.h"
#include "settings/Settings.h"
#include "meter/Measuring.h"


class Selection : public SubMenuList{
	private:
		LapMenu* lap;
		Measuring* meter;
		Settings* settings;

	public:
		Selection(Window*);
		void drawMenu();
		void buttonNext();
};

#endif