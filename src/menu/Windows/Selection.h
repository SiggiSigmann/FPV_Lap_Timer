#ifndef SELECTION_H
#define SELECTION_H

#include "../AbstractMenu.h"
#include "../SubMenuList.h"
#include "../../fpv/Scanner.h"
#include "../../RX5808/channels.h"
#include "tracker/LapMenu.h"
#include "settings/Settings.h"
#include "meter/Measuring.h"



class Selection : public SubMenuList{
	private:
		LapMenu* lap;
		Measuring* meter;
		Settings* settings;

	public:
		Selection(AbstractMenu* , Scanner* sc);
		void draw();
		void buttonNext();
};

#endif