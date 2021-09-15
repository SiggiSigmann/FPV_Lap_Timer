#ifndef MAINMENU_H
#define MAINMENU_H

#include "Menu.h"
#include "pins.h"


class MainMenu : public Menu{
	private:
		Menu* active;
		boolean up=false;
		boolean down=false;
		boolean next=false;
		boolean prev=false;
		void acitvate(Menu* activateion);
		void acitvateMe();


	public:
		MainMenu(Adafruit_SSD1306* d);
		void draw();
		void setMainScreen(Menu* m);
		void run();
		void processButton();
		void buttonPrev();
		void buttonNext();
		void buttonUp();
		void buttonDown();
};

#endif