#include "SDSettings.h"


SDSettings::SDSettings(GUI* m):Menu("SD Card",m){
}

void SDSettings::drawMenu(){
	setExtraInfromation(String(sdCard->sdCardExists() ? "+":"-") + String(sdCard->getInit() ? "+":"-"));

	drawPoint("update");
	drawPoint("init card");
	drawPoint("clean card");
	drawPoint("new file");
	drawPoint("append");
	drawInfo("check: " + String(sdCard->sdCardExists()));
	drawInfo("init: " + String(sdCard->getInit()));
	drawInfo("laps: " + String(sdCard->getNumberOfLaps()));
	drawInfo("tracks: " + String(sdCard->getNumberOfTracks()));
	drawInfo("type: " + sdCard->getCardType());
	drawInfo("size: " + String(sdCard->getCardSize()));
	drawInfo("sec: " + String(sdCard->getNumSectors()));
	drawInfo("sec size: " + String(sdCard->getSectorSize()));
	drawInfo("total kb: " + String(sdCard->getTotalBytes()));
	drawInfo("used kb: " + String(sdCard->getUsedBytes()));
	drawInfo("file: " + String(sdCard->getCurrentFile()));

	
}

void SDSettings::buttonNext(){
	switch (activeEntry){
		case 0:
			sdCard->update();
			break;
		case 1:
			sdCard->initialize();
			break;
		case 2:
			sdCard->clean();
			break;
		case 3:
			sdCard->generateNewFile();
			break;
		case 4:
			sdCard->appendToNewFile(String("hi\n"));
			break;
	}
}



