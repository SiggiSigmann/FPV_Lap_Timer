#ifndef MAINMENU_H
#define MAINMENU_H

#include "AbstractMenu.h"
#include "pins.h"

#define LONGEPRESS 1500
#define FREQUENZE 100

/**
 * Main Menu class to handel draw and buttons
 */
class MainMenu : public AbstractMenu{
	private:
		AbstractMenu* active;						//holds instance of MenuPoint which is corrently active

		//Buttonstuff
		boolean up=false;
		boolean down=false;
		boolean next=false;
		boolean prev=false;

		boolean longup=false;
		boolean longdown=false;
		boolean longnext=false;
		boolean longprev=false;

		unsigned long pressedUp = 0;
		unsigned long pressedDown = 0;
		unsigned long pressedNext = 0;
		unsigned long pressedPrev = 0;

		unsigned long last = millis();

		void acitvate(AbstractMenu* activateion);
		void acitvateMe();

	public:
		MainMenu();
		void draw();
		void setMainScreen(AbstractMenu* m);		//Fiven Menu will be the main screen and dispülayd after startup
		void run();							//hav to be calles in Main loop to draw display and process buttons

		//Button stuff
		void processButton();
		void buttonPrev();
		void buttonNext();
		void buttonUp();
		void buttonDown();
};

#endif