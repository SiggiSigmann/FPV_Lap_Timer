#ifndef METER_H
#define METER_H

#include "../../Menu.h"
#include "../../MenuList.h"
#include "../../../fpv/Scanner.h"
#include "..././../RX5808/channels.h"
#include "ChannelScanner.h"
#include "RSSIMeter.h"

class Measuring  : public MenuList{
	private:
		//options
		RSSIMeter* rssiMeter;
		ChannelScanner* osci;

	public:
		Measuring(Adafruit_SSD1306* , Menu* , Scanner* sc);
		void draw();
		void buttonNext();
};

#endif