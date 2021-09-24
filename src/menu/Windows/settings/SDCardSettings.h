#ifndef SDCARDSET_H
#define SDCARDSET_H

#include "../../Menu.h"
#include "../../MenuList.h"
#include "../../../util/sdcard.h"

class SDCardSettings : public MenuList{
	private:

	public:
		SDCardSettings(Adafruit_SSD1306* , Menu*);
		void draw();
		void buttonNext();
};

#endif