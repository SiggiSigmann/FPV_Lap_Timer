#ifndef METER_H
#define METER_H

#include "../../Menu.h"
#include "../../../fpv/Scanner.h"
#include "..././../RX5808/channels.h"
#include "ChannelScanner.h"
#include "RSSIMeter.h"


class Measuring  : public Menu{
	private:
		//options
		RSSIMeter* rssiMeter;
		ChannelScanner* osci;

	public:
		Measuring(GUI*);
		void drawMenu();
		void buttonNext();
};

#endif