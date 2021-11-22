#ifndef OSC_H
#define OSC_H

#include "../../Frame.h"
#include "../../../RX5808/channels.h"
#include "../../../util/util.h"
#include "../../../fpv/Scanner.h"

#include "../../../periferal/gps.h"

class ChannelScanner : public Frame{
	private:
		byte i = 0;					//index of scann
		
	public:
		ChannelScanner(GUI*);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif