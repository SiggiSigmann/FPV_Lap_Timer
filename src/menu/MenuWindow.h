#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include "AbstractMenu.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/**
 * MenuPoint can be inhered from to create and entry in the menu structure
 */
class MenuWindow : public AbstractMenu{
	protected:
		AbstractMenu* parent;

	public:
		MenuWindow(String name, Adafruit_SSD1306* d, AbstractMenu* m);
		void setParent(AbstractMenu*);
		void acitvate(AbstractMenu* activateion);
		void acitvateMe();
		void buttonPrev();

		//sup class newds to implement:
		//virtual void buttonNext()  = 0;
		//virtual void buttonUp()  = 0;
		//virtual void buttonDown()  = 0;

};

#endif