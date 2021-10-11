#ifndef RSSIMETER_H
#define RSSIMETER_H

#include "../../AbstractMenu.h"
#include "../../MenuWindow.h"
#include "../../../RX5808/channels.h"
#include "../../../util/util.h"
#include "../../../fpv/Scanner.h"

#define LASTVALUES 120
#define DELAVFORRSSI 100

class RSSIMeter : public MenuWindow{
	private:
		int channel = 0;				//channel to scan
		int old[LASTVALUES] = {0};				// last 120 values

	public:
		RSSIMeter(AbstractMenu*);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
};

#endif