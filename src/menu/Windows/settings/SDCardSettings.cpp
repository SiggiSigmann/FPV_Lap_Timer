#include "SDCardSettings.h"


SDCardSettings::SDCardSettings(AbstractMenu* m):SubMenuList("SDCard SETTINGS",m){
}

void SDCardSettings::drawMenu(){
	drawPoint("Clear");
	drawPoint("Init");
	//drawInfo(String(getStorageSize())+ " Mb");

}

void SDCardSettings::buttonNext(){
	switch (activePoint){
		case 0:
			//deleteAll();
			break;
		
		case 1:
			//initSD();
			break;
	}
}