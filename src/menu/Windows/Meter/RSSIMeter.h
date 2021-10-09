#ifndef RSSIMETER_H
#define RSSIMETER_H

#include "../../AbstractMenu.h"
#include "../../MenuWindow.h"
#include "../../../fpv/Scanner.h"
#include "../../../RX5808/channels.h"
#include "../../../util/util.h"

#define LASTVALUES 120
#define DELAVFORRSSI 100

class RSSIMeter : public MenuWindow{
	private:
		Scanner* scan;
		int channel = 0;				//channel to scan
		int old[LASTVALUES] = {0};				// last 120 values

	public:
		RSSIMeter(AbstractMenu* , Scanner*);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
};

#endif