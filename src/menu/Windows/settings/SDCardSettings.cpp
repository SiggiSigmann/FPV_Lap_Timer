#include "SDCardSettings.h"


SDCardSettings::SDCardSettings(GUI* m):Menu("SDCard SETTINGS",m){
}

void SDCardSettings::drawMenu(){
	drawPoint("Clear");
	drawPoint("Init");
	//drawInfo(String(getStorageSize())+ " Mb");

}

void SDCardSettings::buttonNext(){
	switch (activeEntry){
		case 0:
			//deleteAll();
			break;
		
		case 1:
			//initSD();
			break;
	}
}