#ifndef MENUPOINT_H
#define MENUPOINT_H

#include "Menu.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class MenuPoint : public Menu{
	protected:
		Menu* parent;

	public:
		MenuPoint(Adafruit_SSD1306* d, Menu* m);
		void setParent(Menu*);
		void acitvate(Menu* activateion);
		void acitvateMe();
		void buttonPrev();

		//virtual void buttonNext()  = 0;
		//virtual void buttonUp()  = 0;
		//virtual void buttonDown()  = 0;

};

#endif