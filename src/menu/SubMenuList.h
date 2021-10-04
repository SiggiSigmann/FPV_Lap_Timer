#ifndef SUBMENULIST_H
#define SUBMENULIST_H

#include "AbstractMenu.h"
#include "MenuWindow.h"

class SubMenuList : public MenuWindow{
	private:
		byte numberOfPoints;

	protected:
		byte activePoint = 0;

	public:
		SubMenuList(Adafruit_SSD1306* , AbstractMenu*, byte);
		void buttonUp();
		void buttonDown();
		void drawPoint(byte, String, int px=120);			//draw a menupoint (index, name)
		void drawInfo(byte, String, int px=120);			//draw a menupoint (index, name)
		byte getNumberOfPoints();
};

#endif