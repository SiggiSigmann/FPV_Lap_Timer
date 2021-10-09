#ifndef SETTINGS_H
#define SETTINGS_H

#include "../../AbstractMenu.h"
#include "../../SubMenuList.h"
#include "../../../fpv/Scanner.h"
#include "ScanSettings.h"
#include "GPSSettings.h"
#include "SDCardSettings.h"



class Settings : public SubMenuList{
	private:
		ScanSettings* scanSettings;
		GPSSettings* gpsSettings;
		SDCardSettings* sdcardsettings;

	public:
		Settings(AbstractMenu*);
		void drawMenu();
		void buttonNext();
};

#endif