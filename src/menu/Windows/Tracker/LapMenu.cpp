#include "LapMenu.h"

LapMenu::LapMenu(AbstractMenu* m, Scanner* sc):SubMenuList("MENU - LAPTRACKER",m){
	//create Tracker
	DroneDetector* detector = new DroneDetector();

	sfc = new ScanForDrones(this,sc,detector);
	dt = new DroneTracker(this,sc,detector);
	tr = new Detectorsettings(this,detector);

	TrackManager* tman = new TrackManager();
	tm = new TrackMenu(this,tman);
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
			tr->acitvateMe();
			break;
	}
}

