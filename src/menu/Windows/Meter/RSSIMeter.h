#ifndef RSSIMETER_H
#define RSSIMETER_H

#include "../../Menu.h"
#include "../../MenuPoint.h"
#include "../../../fpv/Scanner.h"
#include "../../../RX5808/channels.h"

class RSSIMeter : public MenuPoint{
	private:
		FPVScanner* scan;
		boolean actvescann = false;
		int channel = 0;
		void osci();
		void drawBottomline();
		byte old[120] = {0};

	public:
		RSSIMeter(Adafruit_SSD1306* , Menu* , FPVScanner*);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
};

#endif