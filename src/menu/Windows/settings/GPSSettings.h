#ifndef GPSSETTINGS_H
#define GPSSETTINGS_H

#include "../../Menu.h"
#include "../../MenuList.h"
#include "../../../util/gps.h"


class GPSSettings : public MenuList{
	private:
		

	public:
		GPSSettings(Adafruit_SSD1306* , Menu*);
		void draw();
		void buttonNext();
};

#endif