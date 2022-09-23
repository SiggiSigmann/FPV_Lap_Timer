#ifndef SDSETTINGS_H
#define SDSETTINGS_H

#include "../../Menu.h"
#include "../../../periferal/sdCard.h"

class SDSettings : public Menu{
	private:

	public:
		SDSettings(GUI*);
		void drawMenu();
		void buttonNext();
};

#endif