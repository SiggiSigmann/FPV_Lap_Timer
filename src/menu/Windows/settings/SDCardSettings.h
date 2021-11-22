#ifndef SDCARDSET_H
#define SDCARDSET_H

#include "../../Menu.h"

class SDCardSettings : public Menu{
	private:

	public:
		SDCardSettings(GUI*);
		void drawMenu();
		void buttonNext();
};

#endif