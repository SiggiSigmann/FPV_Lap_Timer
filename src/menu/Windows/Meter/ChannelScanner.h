#ifndef OSC_H
#define OSC_H

#include "../../Menu.h"
#include "../../MenuPoint.h"
#include "../../../fpv/Scanner.h"
#include "../../../RX5808/channels.h"
#include "../../../util/util.h"

class ChannelScanner : public MenuPoint{
	private:
		Scanner* scan;
		byte i = 0;					//index of scann
		
	public:
		ChannelScanner(Adafruit_SSD1306* , Menu* , Scanner*);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif