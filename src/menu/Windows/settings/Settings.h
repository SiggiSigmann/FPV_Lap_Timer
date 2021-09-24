#ifndef SETTINGS_H
#define SETTINGS_H

#include "../../Menu.h"
#include "../../MenuList.h"
#include "../../../fpv/Scanner.h"
#include "ScanSettings.h"
#include "GPSSettings.h"
#include "SDCardSettings.h"



class Settings : public MenuList{
	private:
		ScanSettings* scanSettings;
		GPSSettings* gpsSettings;
		SDCardSettings* sdcardsettings;

	public:
		Settings(Adafruit_SSD1306* , Menu*, Scanner* sc);
		void draw();
		void buttonNext();
};

#endif