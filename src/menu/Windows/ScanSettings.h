#ifndef ScanSettings_H
#define ScanSettings_H

#include "../Menu.h"
#include "../MenuPoint.h"
#include "../../fpv/Scanner.h"
#include "../../fpv/LapTracker.h"
#include "../../RX5808/channels.h"
#include "Osciloskope.h"
#include "RSSIMeter.h"

#define MENUENTRIES 2

class ScanSettings : public MenuPoint{
	private:
		int activePoint = 0;
		FPVScanner* sc;
		LapTracker* tracker;

	public:
		ScanSettings(Adafruit_SSD1306* , Menu*, FPVScanner* sc);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
};

#endif