#include "SDSettings.h"


SDSettings::SDSettings(GUI* m):Menu("SD Card",m){
}

void SDSettings::drawMenu(){

	drawPoint("update");
	drawInfo("check: " + String(sdCard->sdCardExists()));
	drawInfo("type: " + sdCard->getCardType());
	drawInfo("size: " + String(sdCard->getCardSize()));
	drawInfo("sec: " + String(sdCard->getNumSectors()));
	drawInfo("sec size: " + String(sdCard->getSectorSize()));
	drawInfo("total kb: " + String(sdCard->getTotalBytes()));
	drawInfo("used kb: " + String(sdCard->getUsedBytes()));

}

void SDSettings::buttonNext(){
	switch (activeEntry){
		case 0:
			sdCard->update();
			break;
	}
}



