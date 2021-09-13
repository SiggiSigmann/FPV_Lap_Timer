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

		//virtual void draw()  = 0;
		//virtual void processButton()  = 0;

};

#endif