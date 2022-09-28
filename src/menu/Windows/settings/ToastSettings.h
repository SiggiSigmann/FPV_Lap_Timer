#ifndef TOASTSETTINGS_H
#define TOASTSETTINGS_H

#include <Arduino.h>
#include "../../Menu.h"
#include "../../Toast.h"

class ToastSettings : public Menu{
	private:

	public:
		ToastSettings(GUI*);
		void drawMenu();
		void buttonNext();


};


#endif