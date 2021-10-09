#ifndef TRACKERMENU_H
#define TRACKERMENU_H

#include "../../../AbstractMenu.h"
#include "../../../SubMenuList.h"
#include "../../../../fpv/TrackManager.h"
#include "../../../../RX5808/channels.h"


class TrackMenu : public SubMenuList{
	private:
		TrackManager* tm;
		boolean editNumber = false;


	public:
		TrackMenu(AbstractMenu*, TrackManager*);
		void drawMenu();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif