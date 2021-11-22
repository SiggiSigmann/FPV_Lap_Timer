#ifndef OSC_H
#define OSC_H

#include "../../Window.h"
#include "../../MenuWindow.h"
#include "../../../RX5808/channels.h"
#include "../../../util/util.h"
#include "../../../fpv/Scanner.h"

class ChannelScanner : public MenuWindow{
	private:
		byte i = 0;					//index of scann
		
	public:
		ChannelScanner(Window*);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif