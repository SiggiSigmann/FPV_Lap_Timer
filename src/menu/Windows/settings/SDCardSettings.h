#ifndef SDCARDSET_H
#define SDCARDSET_H

#include "../../Window.h"
#include "../../SubMenuList.h"


class SDCardSettings : public SubMenuList{
	private:

	public:
		SDCardSettings(Window*);
		void drawMenu();
		void buttonNext();
};

#endif