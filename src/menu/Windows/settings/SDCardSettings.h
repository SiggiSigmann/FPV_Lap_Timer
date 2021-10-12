#ifndef SDCARDSET_H
#define SDCARDSET_H

#include "../../AbstractMenu.h"
#include "../../SubMenuList.h"


class SDCardSettings : public SubMenuList{
	private:

	public:
		SDCardSettings(AbstractMenu*);
		void drawMenu();
		void buttonNext();
};

#endif