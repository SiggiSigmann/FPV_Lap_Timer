#ifndef ScanSettings_H
#define ScanSettings_H

#include "../../Window.h"
#include "../../SubMenuList.h"
#include "../../../RX5808/channels.h"
#include "../../../fpv/Scanner.h"


class ScanSettings : public SubMenuList{
	private:

	public:
		ScanSettings(Window*);
		void drawMenu();
		void buttonNext();
};

#endif