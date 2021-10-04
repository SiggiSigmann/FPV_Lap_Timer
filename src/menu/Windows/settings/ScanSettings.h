#ifndef ScanSettings_H
#define ScanSettings_H

#include "../../AbstractMenu.h"
#include "../../SubMenuList.h"
#include "../../../fpv/Scanner.h"
#include "../../../RX5808/channels.h"
#include "../../../util/sdcard.h"



class ScanSettings : public SubMenuList{
	private:
		Scanner* sc;

	public:
		ScanSettings(Adafruit_SSD1306* , AbstractMenu*, Scanner* sc);
		void draw();
		void buttonNext();
};

#endif