#ifndef SETTINGS_H
#define SETTINGS_H

#include "../../AbstractMenu.h"
#include "../../SubMenuList.h"
#include "ScanSettings.h"
#include "GPSSettings.h"
#include "SDCardSettings.h"
#include "Detectorsettings.h"
#include "Trackersettings.h"



class Settings : public SubMenuList{
	private:
		ScanSettings* scanSettings;
		GPSSettings* gpsSettings;
		SDCardSettings* sdcardsettings;
		Detectorsettings* detectionSettings;
		TrackerSettings* trakersettings;

	public:
		Settings(AbstractMenu*);
		void drawMenu();
		void buttonNext();
};

#endif