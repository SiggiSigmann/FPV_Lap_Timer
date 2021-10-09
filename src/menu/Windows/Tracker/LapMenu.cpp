#include "LapMenu.h"

LapMenu::LapMenu(AbstractMenu* m):SubMenuList("MENU - LAPTRACKER",m){
	sfc = new ScanForDrones(this);
	dt = new DroneTracker(this);
	tm = new TrackMenu(this);
}

void LapMenu::drawMenu(){
	drawPoint("Scann for Drones");
	drawPoint("Start");
	drawPoint("Tracks");
	drawPoint("Tracker Settings");
}	

void LapMenu::buttonNext(){
	switch (activePoint){
		case 0:
			sfc->acitvateMe();
			break;
		case 1:
			dt->acitvateMe();
			break;
		case 2:
			tm->acitvateMe();
			break;
		case 3:
			//tr->acitvateMe();
			break;
	}
}

