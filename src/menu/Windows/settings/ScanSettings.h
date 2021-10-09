#ifndef ScanSettings_H
#define ScanSettings_H

#include "../../AbstractMenu.h"
#include "../../SubMenuList.h"
#include "../../../RX5808/channels.h"
#include "../../../util/sdcard.h"



class ScanSettings : public SubMenuList{
	private:

	public:
		ScanSettings(AbstractMenu*);
		void drawMenu();
		void buttonNext();
};

#endif