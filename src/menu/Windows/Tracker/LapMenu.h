#ifndef LAPMENU_H
#define LAPMENU_H

#include "../../Menu.h"
#include "../../MenuList.h"
#include "../../../fpv/Scanner.h"
#include "../../../RX5808/channels.h"
#include "ScanForDrones.h"
#include "DroneTracker.h"
#include "Detectorsettings.h"

class LapMenu : public MenuList{
	private:
		ScanForDrones* sfc;
		DroneTracker* dt;
		Detectorsettings* tr;

	public:
		LapMenu(Adafruit_SSD1306* , Menu*, Scanner* sc);
		void draw();
		void buttonNext();
};

#endif