#ifndef TRACKERMENU_H
#define TRACKERMENU_H

#include "../../../Menu.h"
#include "../../../../RX5808/channels.h"
#include "../../../../fpv/TrackManager.h"

class TrackMenu : public Menu{
	private:
		boolean editNumber = false;


	public:
		TrackMenu(GUI*);
		void drawMenu();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif