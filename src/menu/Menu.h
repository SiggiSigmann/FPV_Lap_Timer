#ifndef MENU_H
#define MENU_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/**
 * Can be inhered from to create a MenuPoint
 */
class Menu{
	protected:
		Adafruit_SSD1306* display;
	
	public:
		Menu(Adafruit_SSD1306* d);
		Adafruit_SSD1306* getDisplay();
		
		virtual void draw()  = 0;
		virtual void buttonNext()  = 0;
		virtual void buttonPrev()  = 0;
		virtual void buttonUp()  = 0;
		virtual void buttonDown()  = 0;
		virtual void acitvate(Menu* activateion) = 0;
		virtual void acitvateMe() = 0;

};
#endif