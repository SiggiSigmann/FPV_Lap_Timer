#include "DroneTracker.h"

DroneTracker::DroneTracker(Adafruit_SSD1306* d, Menu* m, Scanner* sc, DroneDetector* detector):MenuList(d,m,4){
	this->sc = sc;
	this->detector = detector;
	this->tracker = new LapTracker(sc);

	multi = new Multidrone(d,this,sc,tracker);
	singel = new Singeldrone(d,this,sc,tracker);

	trackersetings = new TrackerSettings(d,this,tracker);
}

void DroneTracker::draw(){
	//top
	this->display->fillRect(0,0,128,10,BLACK);
	this->display->setCursor(0,0);
	this->display->print("DRONE TRACKER: ");
	this->display->print(detector->getNumberOfDrones());
	this->display->print("|");
	this->display->print(millis()-last);
	last = millis();

	byte idx = 0;
	drawPoint(idx++,"Load Drones");
	drawPoint(idx++,"Singel view");
	drawPoint(idx++,"Multi view");
	drawPoint(idx++,"Settings");

	tracker->update();
}

void DroneTracker::buttonNext(){
	byte* dr = detector->getDroneFreqs();

	switch (activePoint){
		case 0:
			tracker->reset();
			for(int i =0;i<this->detector->getNumberOfDrones();i++){
				tracker->addDrone(dr[i],sc->getNoise()[dr[i]],sc->getLastScan()[dr[i]]);
			}
			if(this->detector->getNumberOfDrones()!=0){
				ok = true;
			}
			break;
			
		case 1:
			if(ok){
				singel->acitvateMe();
			}
			break;

		case 2:
			if(ok){
				multi->acitvateMe();
			}
			break;
		case 3:
				trackersetings->acitvateMe();
			break;
	}
}


