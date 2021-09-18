#ifndef ScanSettings_H
#define ScanSettings_H

#include "../Menu.h"
#include "../MenuList.h"
#include "../../fpv/Scanner.h"
#include "../../RX5808/channels.h"



class ScanSettings : public MenuList{
	private:
		int activePoint = 0;
		Scanner* sc;

	public:
		ScanSettings(Adafruit_SSD1306* , Menu*, Scanner* sc);
		void draw();
		void buttonNext();
};

#endif