#ifndef SCANFORDRONES_H
#define SCANFORDRONES_H

#include "../../Menu.h"
#include "../../MenuPoint.h"
#include "../../../fpv/Scanner.h"
#include "../../../fpv/LapTracker.h"
#include "../../../RX5808/channels.h"

#define MENUENTRIES 4

class ScanForDrones : public MenuPoint{
	private:
		int activePoint = 0;
		FPVScanner* sc;
		LapTracker* tracker;
		int measurement[40];
		byte i = 0;
		boolean scann = false;
		boolean edit = false;
		byte lineidx = 0;
		boolean editline = false;
		boolean drawline = true;
		unsigned long time;

	public:
		ScanForDrones(Adafruit_SSD1306* , Menu*, FPVScanner* sc);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif