#ifndef OSC_H
#define OSC_H

#include "../../AbstractMenu.h"
#include "../../MenuWindow.h"
#include "../../../fpv/Scanner.h"
#include "../../../RX5808/channels.h"
#include "../../../util/util.h"

class ChannelScanner : public MenuWindow{
	private:
		Scanner* scan;
		byte i = 0;					//index of scann
		
	public:
		ChannelScanner(Adafruit_SSD1306* , AbstractMenu* , Scanner*);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif