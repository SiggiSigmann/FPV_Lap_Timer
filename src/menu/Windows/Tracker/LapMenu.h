#ifndef LAPMENU_H
#define LAPMENU_H

#include "../../Menu.h"
#include "../../MenuPoint.h"
#include "../../../fpv/Scanner.h"
#include "../../../RX5808/channels.h"
#include "ScanForDrones.h"

#define MENUENTRIES 2

class LapMenu : public MenuPoint{
	private:
		int activePoint = 0;
		FPVScanner* sc;
		ScanForDrones* sfc;

	public:
		LapMenu(Adafruit_SSD1306* , Menu*, FPVScanner* sc);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
};

#endif