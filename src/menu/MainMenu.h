#ifndef MAINMENU_H
#define MAINMENU_H

#include "Menu.h"


class MainMenu : public Menu{
	private:
		Menu* active;

		void acitvate(Menu* activateion);
		void acitvateMe();


	public:
		MainMenu(Adafruit_SSD1306* d);
		void draw();
		void processButton();
		void setMainScreen(Menu* m);
		void run();
};

#endif