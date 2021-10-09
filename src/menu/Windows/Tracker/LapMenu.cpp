#include "LapMenu.h"

LapMenu::LapMenu(Adafruit_SSD1306* d, AbstractMenu* m, Scanner* sc):SubMenuList("MENU - LAPTRACKER",d,m,4){
	//create Tracker
	DroneDetector* detector = new DroneDetector();

	sfc = new ScanForDrones(d,this,sc,detector);
	dt = new DroneTracker(d,this,sc,detector);
	tr = new Detectorsettings(d,this,detector);

	TrackManager* tman = new TrackManager();
	tm = new TrackMenu(d,this,tman);
}

void LapMenu::draw(){

	byte idx = 0;
	drawPoint(idx++,"Scann for Drones");
	drawPoint(idx++,"Start");
	drawPoint(idx++,"Tracks");
	drawPoint(idx++,"Tracker Settings");
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

