#ifndef MENULIST_H
#define MENULIST_H

#include "Menu.h"
#include "MenuPoint.h"

class MenuList : public MenuPoint{
	private:
		byte numberOfPoints;

	protected:
		byte activePoint = 0;

	public:
		MenuList(Adafruit_SSD1306* , Menu*, byte);
		void buttonUp();
		void buttonDown();
		void drawPoint(byte, String, int px=120);			//draw a menupoint (index, name)
		void drawInfo(byte, String, int px=120);			//draw a menupoint (index, name)
		byte getNumberOfPoints();
};

#endif