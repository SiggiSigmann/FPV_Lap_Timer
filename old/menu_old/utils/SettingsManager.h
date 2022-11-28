#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <map>
#include <Arduino.h>
#include "../../periferal/SDCard.h"
#include "Toast.h"

class SettingsManager{
	private:
		std::map<String, int> settings;
		bool loaded = false;

	public:
		SettingsManager();
		void registerSetting(String key, int value);
		int getSetting(String key);
		void setSettings(String key, int value);

		void loadSettings();
		void storeSettings();
};

extern SettingsManager* settingsManager;

#endif