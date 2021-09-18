#ifndef SCANFORDRONES_H
#define SCANFORDRONES_H

#include "../../Menu.h"
#include "../../MenuList.h"
#include "../../../fpv/Scanner.h"
#include "../../../fpv/DroneDetector.h"
#include "../../../RX5808/channels.h"
#include "../../../util/util.h"

class ScanForDrones : public MenuList{
	private:
		Scanner* scan;
		DroneDetector* tracker;

		//scan for drones
		boolean isScanning = false;
		byte i = 0;					//index of channel
		
		//edit drone channels
		boolean edit = false;
		boolean editline = false;
		byte lineidx = 0;
		boolean drawline = true;
		unsigned long time;

	public:
		ScanForDrones(Adafruit_SSD1306* , Menu*, Scanner*, DroneDetector*);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();
};

#endif