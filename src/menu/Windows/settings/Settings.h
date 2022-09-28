#ifndef SETTINGS_H
#define SETTINGS_H

#include "../../Menu.h"
#include "ScanSettings.h"
#include "GPSSettings.h"
#include "Detectorsettings.h"
#include "Trackersettings.h"
#include "SpeackerCheck.h"
#include "SDSettings.h"
#include "ToastSettings.h"


class Settings : public Menu{
	private:
		ScanSettings* scanSettings;
		GPSSettings* gpsSettings;
		Detectorsettings* detectionSettings;
		TrackerSettings* trakersettings;
		SpeackerCheck* speackerCheck;
		SDSettings* sdSettings;
		ToastSettings* toastSettings;

	public:
		Settings(GUI*);
		void drawMenu();
		void buttonNext();
};

#endif