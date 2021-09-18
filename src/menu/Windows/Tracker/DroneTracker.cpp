#include "DroneTracker.h"

DroneTracker::DroneTracker(Adafruit_SSD1306* d, Menu* m, Scanner* sc, DroneDetector* detector):MenuList(d,m,3){
	this->sc = sc;
	this->detector = detector;
	this->tracker = new LapTracker(sc);

	multi = new Multidrone(d,this,sc,tracker);
	singel = new Singeldrone(d,this,sc,tracker);
}

void DroneTracker::draw(){
	//top
	this->display->fillRect(0,0,128,10,BLACK);
	this->display->setCursor(0,0);
	this->display->print("Drone Tracker:");
	this->display->print(detector->getNumberOfDrones());
	this->display->print("|");
	this->display->print(millis()-last);
	last = millis();

	byte idx = 0;
	drawPoint(idx++,"Load Drones");
	drawPoint(idx++,"Singel view");
	drawPoint(idx++,"Multi view");

	tracker->update();
}

void DroneTracker::buttonNext(){
	byte* dr = detector->getDroneFreqs();

	switch (activePoint){
		case 0:
			for(int i =0;i<this->detector->getNumberOfDrones();i++){
				tracker->addDrone(pgm_read_word_near(channelFreqTable+dr[i]),sc->getNoise()[dr[i]],sc->getLastScan()[dr[i]]);
			}
			break;
			
		case 1:
			singel->acitvateMe();
			break;

		case 2:
			multi->acitvateMe();
			break;
	}
}


