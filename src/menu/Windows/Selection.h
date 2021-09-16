#ifndef SELECTION_H
#define SELECTION_H

#include "../Menu.h"
#include "../MenuPoint.h"
#include "../../fpv/Scanner.h"
#include "../../RX5808/channels.h"
#include "LapMenu.h"
#include "ScanSettings.h"
#include "Meter/Meter.h"

#define MENUENTRIES 3

class Selection : public MenuPoint{
	private:
		FPVScanner* scan;
		LapMenu* lap;
		byte activePoint = 0;
		Meter* meter;
		ScanSettings* scanSettngs;

	public:
		Selection(Adafruit_SSD1306* , Menu* , FPVScanner* sc);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
};

#endif