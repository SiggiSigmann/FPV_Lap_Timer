#ifndef GPSSETTINGS_H
#define GPSSETTINGS_H

#include "../../AbstractMenu.h"
#include "../../SubMenuList.h"
#include "../../../util/gps.h"


class GPSSettings : public SubMenuList{
	private:
		

	public:
		GPSSettings(Adafruit_SSD1306* , AbstractMenu*);
		void draw();
		void buttonNext();
};

#endif