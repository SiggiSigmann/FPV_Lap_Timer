#ifndef STORAGE_MANAGER_H
#define STORAGE_MANAGER_H

#include <SimpleMap.h>
#include "../periferals/persistance.h"
#include "ToastManager.h"

class SettingsManager{
	private:
		SimpleMap<String, String>* settings;
		IPersistance* persistance;

		unsigned long lastUpdateTime;

		void setPersistance(IPersistance*);

		bool isRead = false;

	public:
		void persistSettings();
		void loadSettings();

		SettingsManager(IPersistance* pers){this->setPersistance(pers);};
		~SettingsManager( );


		String get(String);

		void set(String, String);
};

extern SettingsManager* settingsm;

#endif