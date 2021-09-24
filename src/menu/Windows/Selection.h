#ifndef SELECTION_H
#define SELECTION_H

#include "../Menu.h"
#include "../MenuList.h"
#include "../../fpv/Scanner.h"
#include "../../RX5808/channels.h"
#include "Tracker/LapMenu.h"
#include "settings/Settings.h"
#include "meter/Measuring.h"



class Selection : public MenuList{
	private:
		LapMenu* lap;
		Measuring* meter;
		Settings* settings;

	public:
		Selection(Adafruit_SSD1306* , Menu* , Scanner* sc);
		void draw();
		void buttonNext();
};

#endif