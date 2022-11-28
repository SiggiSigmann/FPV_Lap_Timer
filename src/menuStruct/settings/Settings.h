#ifndef Settings_H
#define Settings_H

#include "../../menu/ui/Menu.h"
#include <Arduino.h>
#include "GPSSettings.h"
#include "DHTSettings.h"

class Settings: public Menu{
	private:

	public:
		Settings();
		
		//actions before and after
		void preActions();
		void postActions();

		void buttonAction(byte);
};



#endif