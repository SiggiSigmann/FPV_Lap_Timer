#ifndef METER_H
#define METER_H

#include "../../AbstractMenu.h"
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
		Measuring(AbstractMenu* , Scanner* sc);
		void draw();
		void buttonNext();
};

#endif