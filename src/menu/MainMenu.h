#ifndef MAINMENU_H
#define MAINMENU_H

#include "Menu.h"
#include "pins.h"

/**
 * Main Menu class to handel draw and buttons
 */
class MainMenu : public Menu{
	private:
		Menu* active;						//holds instance of MenuPoint which is corrently active

		//Buttonstuff
		boolean up=false;
		boolean down=false;
		boolean next=false;
		boolean prev=false;


		void acitvate(Menu* activateion);
		void acitvateMe();

	public:
		MainMenu(Adafruit_SSD1306* d);
		void draw();
		void setMainScreen(Menu* m);		//Fiven Menu will be the main screen and dispülayd after startup
		void run();							//hav to be calles in Main loop to draw display and process buttons

		//Button stuff
		void processButton();
		void buttonPrev();
		void buttonNext();
		void buttonUp();
		void buttonDown();
};

#endif