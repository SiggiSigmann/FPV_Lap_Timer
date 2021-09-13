#ifndef MENU_H
#define MENU_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


class Menu{
	protected:
		Adafruit_SSD1306* display;
	
	public:
		Menu(Adafruit_SSD1306* d);
		virtual void draw()  = 0;
		virtual void processButton()  = 0;
		virtual void acitvate(Menu* activateion) = 0;
		virtual void acitvateMe() = 0;
};
#endif