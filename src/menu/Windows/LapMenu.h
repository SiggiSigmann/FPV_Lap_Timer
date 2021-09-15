#ifndef LAPMENU_H
#define LAPMENU_H

#include "../Menu.h"
#include "../MenuPoint.h"
#include "../../fpv/Scanner.h"
#include "../../RX5808/channels.h"
#include "Osciloskope.h"
#include "RSSIMeter.h"

#define MENUENTRIES 3

class LapMenu : public MenuPoint{
	private:
		int activePoint = 0;

	public:
		LapMenu(Adafruit_SSD1306* , Menu*);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
};

#endif