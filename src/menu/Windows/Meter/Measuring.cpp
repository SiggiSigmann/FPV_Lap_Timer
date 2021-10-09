#include "Measuring.h"

Measuring::Measuring(AbstractMenu* m, Scanner* sc):SubMenuList("MEASURING",m){
	osci = new ChannelScanner(this, sc);
	rssiMeter = new RSSIMeter(this, sc);
}

void Measuring::drawMenu(){
	drawPoint("Channel Scanner");
	drawPoint("RSSI Oscilloscope");
}	

void Measuring::buttonNext(){
	switch (this->activePoint){
		case 0:
			osci->acitvateMe();
			break;
			
		case 1:
			rssiMeter->acitvateMe();
			break;
	}
}
