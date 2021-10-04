#ifndef TRACKERMENU_H
#define TRACKERMENU_H

#include "../../../Menu.h"
#include "../../../MenuList.h"
#include "../../../../fpv/TrackManager.h"
#include "../../../../RX5808/channels.h"


class TrackMenu : public MenuList{
	private:
		TrackManager* tm;
		boolean editNumber = false;


	public:
		TrackMenu(Adafruit_SSD1306* , Menu*, TrackManager*);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif