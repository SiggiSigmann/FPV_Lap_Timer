#ifndef SETTINGS_H
#define SETTINGS_H

#include "../../Menu.h"
#include "ScanSettings.h"
#include "GPSSettings.h"
#include "SDCardSettings.h"
#include "Detectorsettings.h"
#include "Trackersettings.h"
#include "SpeackerCheck.h"



class Settings : public Menu{
	private:
		ScanSettings* scanSettings;
		GPSSettings* gpsSettings;
		SDCardSettings* sdcardsettings;
		Detectorsettings* detectionSettings;
		TrackerSettings* trakersettings;
		SpeackerCheck* speackerCheck;

	public:
		Settings(GUI*);
		void drawMenu();
		void buttonNext();
};

#endif