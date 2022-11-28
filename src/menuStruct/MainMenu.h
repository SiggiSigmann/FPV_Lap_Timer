#ifndef MAINMENU_H
#define MAINMENU_H

#include "../menu/ui/Menu.h"
#include <Arduino.h>
#include "settings/Settings.h"

class MainMenu: public Menu{
	private:

	public:
		MainMenu();
		
		//actions before and after
		void preActions();
		void postActions();

		void buttonAction(byte);
};



#endif