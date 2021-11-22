#ifndef ScanSettings_H
#define ScanSettings_H

#include "../../Menu.h"
#include "../../../RX5808/channels.h"
#include "../../../fpv/Scanner.h"


class ScanSettings : public Menu{
	private:

	public:
		ScanSettings(GUI*);
		void drawMenu();
		void buttonNext();
};

#endif