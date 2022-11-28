#ifndef MENUE_CONTROLLER_H
#define MENUE_CONTROLLER_H

#include "base/StackController.h"
#include "base/SettingsManager.h"
#include "base/ToastManager.h"
#include "base/ToneManager.h"
#include "periferals/display.h"
#include "periferals/pins.h"

#define LONGEPRESS 1000
#define FREQUENZE 100

class Window;
class StackController;

class MenuController{
	private:
		StackController* sc;
		SettingsManager* sm; 

		Window* activeWindow;

		unsigned long lastUpdateTime = millis();

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

	public:
		MenuController(Window*);

		void run();	

		void draw();
		void processButton();

		void buttonPrev();
		void buttonNext();
		void buttonUp();
		void buttonDown();

		void setActiveWindow(Window*);
		void oneWindowBack();
		void windowBack();
};



extern MenuController* menuController;

#endif