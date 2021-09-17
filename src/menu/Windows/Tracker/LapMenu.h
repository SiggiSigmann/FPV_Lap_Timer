#ifndef LAPMENU_H
#define LAPMENU_H

#include "../../Menu.h"
#include "../../MenuPoint.h"
#include "../../../fpv/Scanner.h"
#include "../../../RX5808/channels.h"
#include "ScanForDrones.h"
#include "DroneTracker.h"
#include "Trackersettings.h"

#define MENUENTRIES 3

class LapMenu : public MenuPoint{
	private:
		int activePoint = 0;
		FPVScanner* sc;
		ScanForDrones* sfc;
		DroneTracker* dt;
		Trackersettings* tr;


	public:
		LapMenu(Adafruit_SSD1306* , Menu*, FPVScanner* sc);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
};

#endif