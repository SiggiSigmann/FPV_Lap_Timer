#include "LapMenu.h"

LapMenu::LapMenu(GUI* m):Menu("MENU - LAPTRACKER",m){
	sfc = new ScanForDrones(this);
	dt = new DroneTracker(this);
	tm = new TrackMenu(this);
}

void LapMenu::drawMenu(){
	drawPoint("Scann for Drones");
	drawPoint("Start");
	drawPoint("Tracks");
}	

void LapMenu::buttonNext(){
	switch (activeEntry){
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

