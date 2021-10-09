#include "Measuring.h"

Measuring::Measuring(AbstractMenu* m):SubMenuList("MEASURING",m){
	osci = new ChannelScanner(this);
	rssiMeter = new RSSIMeter(this);
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
