#ifndef ScanSettings_H
#define ScanSettings_H

#include "../Menu.h"
#include "../MenuList.h"
#include "../../fpv/Scanner.h"
#include "../../fpv/LapTracker.h"
#include "../../RX5808/channels.h"



class ScanSettings : public MenuList{
	private:
		int activePoint = 0;
		Scanner* sc;
		LapTracker* tracker;

	public:
		ScanSettings(Adafruit_SSD1306* , Menu*, Scanner* sc);
		void draw();
		void buttonNext();
};

#endif