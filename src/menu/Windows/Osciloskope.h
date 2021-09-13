#ifndef OSC_H
#define OSC_H

#include "../Menu.h"
#include "../MenuPoint.h"

class Osciloskope : public MenuPoint{
	private:
	public:
		Osciloskope(Adafruit_SSD1306* d, Menu* parent);

		void draw();
		void processButton();
};

#endif