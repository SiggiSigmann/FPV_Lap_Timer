#include "SDCardSettings.h"


SDCardSettings::SDCardSettings(Adafruit_SSD1306* d, Menu* m):MenuList(d,m,2){
}

void SDCardSettings::draw(){
	//top
	this->display->setCursor(0,0);
	this->display->print("SDCard SETTINGS:");

	byte idx=0;
	drawPoint(idx++,"Clear");
	drawPoint(idx++,"Init");
	drawInfo(idx++,String(getStorageSize())+ " Mb");

}

void SDCardSettings::buttonNext(){
	switch (activePoint){
		case 0:
			deleteAll();
			break;
		
		case 1:
			initSD();
			break;
	}
}