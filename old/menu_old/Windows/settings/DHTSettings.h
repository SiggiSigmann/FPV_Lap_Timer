#ifndef DHTSettings_H
#define DHTSettings_H

#include "../../Menu.h"
#include "../../../periferal/DHTSensor.h"

class DHTSettings : public Menu{
	public:
		DHTSettings(GUI*);
		void drawMenu();
		void buttonNext();
};

#endif