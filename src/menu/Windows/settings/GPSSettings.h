#ifndef GPSSETTINGS_H
#define GPSSETTINGS_H

#include "../../AbstractMenu.h"
#include "../../SubMenuList.h"
#include "../../../util/gps.h"


class GPSSettings : public SubMenuList{
	private:
		

	public:
		GPSSettings(AbstractMenu*);
		void drawMenu();
		void buttonNext();
};

#endif