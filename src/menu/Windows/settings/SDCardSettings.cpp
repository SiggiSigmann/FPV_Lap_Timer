#include "SDCardSettings.h"


SDCardSettings::SDCardSettings(AbstractMenu* m):SubMenuList("SDCard SETTINGS",m,2){
}

void SDCardSettings::draw(){
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