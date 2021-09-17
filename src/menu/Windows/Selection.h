#ifndef SELECTION_H
#define SELECTION_H

#include "../Menu.h"
#include "../MenuList.h"
#include "../../fpv/Scanner.h"
#include "../../RX5808/channels.h"
#include "Tracker/LapMenu.h"
#include "ScanSettings.h"
#include "meter/Measuring.h"



class Selection : public MenuList{
	private:
		LapMenu* lap;
		Measuring* meter;
		ScanSettings* scanSettings;

	public:
		Selection(Adafruit_SSD1306* , Menu* , Scanner* sc);
		void draw();
		void buttonNext();
};

#endif