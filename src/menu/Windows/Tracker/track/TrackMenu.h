#ifndef TRACKERMENU_H
#define TRACKERMENU_H

#include "../../../AbstractMenu.h"
#include "../../../SubMenuList.h"
#include "../../../../RX5808/channels.h"
#include "../../../../fpv/TrackManager.h"

class TrackMenu : public SubMenuList{
	private:
		boolean editNumber = false;


	public:
		TrackMenu(AbstractMenu*);
		void drawMenu();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif