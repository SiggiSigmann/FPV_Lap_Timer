#include "Measuring.h"

Measuring::Measuring(Adafruit_SSD1306* d, AbstractMenu* m, Scanner* sc):SubMenuList(d,m,2){
	osci = new ChannelScanner(d, this, sc);
	rssiMeter = new RSSIMeter(d, this, sc);
}

void Measuring::draw(){
	this->display->setCursor(0,0);
	this->display->print("MEASURING:");

	//menu
	byte idx = 0;
	drawPoint(idx++,"Channel Scanner");
	drawPoint(idx++,"RSSI Oscilloscope");
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
