#ifndef SCANFORDRONES_H
#define SCANFORDRONES_H

#include <Arduino.h>
#include "../../AbstractMenu.h"
#include "../../SubMenuList.h"
#include "../../../RX5808/channels.h"
#include "../../../util/util.h"
#include "../../../fpv/DroneDetector.h"
#include "../../../fpv/Scanner.h"

class ScanForDrones : public SubMenuList{
	private:
		//scan for drones
		boolean isScanning = false;
		byte i = 0;					//index of channel
		
		//edit drone channels
		boolean edit = false;
		boolean editline = false;
		boolean deleteDrone = false;
		byte lineidx = 0;
		boolean drawline = true;
		unsigned long time;

	public:
		ScanForDrones(AbstractMenu*);
		void drawMenu();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif