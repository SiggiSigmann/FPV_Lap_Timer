#ifndef METER_H
#define METER_H

#include "../../Menu.h"
#include "../../MenuPoint.h"
#include "../../../fpv/Scanner.h"
#include "..././../RX5808/channels.h"
#include "Osciloskope.h"
#include "RSSIMeter.h"

#define MENUENTRIES 2

class Meter : public MenuPoint{
	private:
		Meter* scan;
		byte activePoint = 0;
		Osciloskope* osci;
		RSSIMeter* rssi;
		FPVScanner* sc;

	public:
		Meter(Adafruit_SSD1306* , Menu* , FPVScanner* sc);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
};

#endif