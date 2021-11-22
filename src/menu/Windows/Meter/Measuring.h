#ifndef METER_H
#define METER_H

#include "../../Window.h"
#include "../../SubMenuList.h"
#include "../../../fpv/Scanner.h"
#include "..././../RX5808/channels.h"
#include "ChannelScanner.h"
#include "RSSIMeter.h"


class Measuring  : public SubMenuList{
	private:
		//options
		RSSIMeter* rssiMeter;
		ChannelScanner* osci;

	public:
		Measuring(Window*);
		void drawMenu();
		void buttonNext();
};

#endif