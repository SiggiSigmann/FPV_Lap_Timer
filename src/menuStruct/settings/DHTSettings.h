#ifndef DHTSettings_H
#define DHTSettings_H

#include "../../menu/ui/Menu.h"
#include "../../menu/ui/MenuEntry.h"
#include "../../periferal/DHTSensor.h"

class DHTSettings : public Menu{
	public:
		DHTSettings();

		//actions before and after
		void preActions();
		void postActions();

		void buttonAction(byte);

		void menuDraw();

		String updateEntry(byte);
};

#endif