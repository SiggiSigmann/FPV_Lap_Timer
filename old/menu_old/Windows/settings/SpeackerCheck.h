#ifndef SPECKERCHECK_H
#define SPECKERCHECK_H

#include <Arduino.h>
#include "../../Menu.h"
#include "../../../periferal/tonegenerator.h"

class SpeackerCheck : public Menu{
	private:
		boolean playthough = false;
		unsigned long playTime = 0;
		byte soundIdx = 0;

	public:
		SpeackerCheck(GUI*);
		void drawMenu();
		void buttonNext();
		void buttonPrev();

};


#endif