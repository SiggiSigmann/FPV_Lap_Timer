#ifndef SPECKERCHECK_H
#define SPECKERCHECK_H

#include <Arduino.h>
#include "../../Window.h"
#include "../../SubMenuList.h"
#include "../../../periferal/tonegenerator.h"

class SpeackerCheck : public SubMenuList{
	private:
		boolean playthough = false;
		unsigned long playTime = 0;
		byte soundIdx = 0;

	public:
		SpeackerCheck(Window*);
		void drawMenu();
		void buttonNext();
		void buttonPrev();

};


#endif