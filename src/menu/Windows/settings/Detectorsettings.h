#ifndef DETECTORSETTINGS_H
#define DETECTORSETTINGS_H

#include <Arduino.h>
#include "../../AbstractMenu.h"
#include "../../SubMenuList.h"

class Detectorsettings : public SubMenuList{
	private:
		boolean editNumber;

	public:
		Detectorsettings(AbstractMenu*);
		void drawMenu();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif