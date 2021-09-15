#ifndef OSC_H
#define OSC_H

#include "../Menu.h"
#include "../MenuPoint.h"
#include "../../fpv/Scanner.h"
#include "../../RX5808/channels.h"

class Osciloskope : public MenuPoint{
	private:
		FPVScanner* scan;
		boolean actvescann = false;
		byte i = 0;

		void osci();
		void drawBottomline();
		
	public:
		Osciloskope(Adafruit_SSD1306* , Menu* , FPVScanner*);
		void draw();
		void processButton();
};

#endif