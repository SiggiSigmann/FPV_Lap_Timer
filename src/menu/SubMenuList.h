#ifndef SUBMENULIST_H
#define SUBMENULIST_H

#include "AbstractMenu.h"
#include "MenuWindow.h"

class SubMenuList : public MenuWindow{
	private:
		byte numberOfPoints;
		byte idx = 0;
		byte options = 0;
		byte displaoffset=0;

	protected:
		byte activePoint = 0;

	public:
		SubMenuList(String name, AbstractMenu*);
		void buttonUp();
		void buttonDown();
		void drawPoint(String, int px=125);			//draw a menupoint (index, name)
		void drawInfo(String, int px=125);			//draw a menupoint (index, name)
		void draw() final;
		byte getNumberOfPoints();

		virtual void drawMenu()  = 0;
};

#endif