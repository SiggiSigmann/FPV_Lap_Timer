#include "DroneTracker.h"

DroneTracker::DroneTracker(AbstractMenu* m, Scanner* sc, DroneDetector* detector):SubMenuList("DRONE TRACKER",m,4){
	this->sc = sc;
	this->detector = detector;
	this->tracker = new LapTracker(sc);

	multi = new Multidrone(this,sc,tracker);
	singel = new Singeldrone(this,sc,tracker);

	trackersetings = new TrackerSettings(this,tracker);

	setExtra(String(detector->getNumberOfDrones()));
}

void DroneTracker::draw(){
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
			setExtra(String(detector->getNumberOfDrones()));
			multi->updateDrones();
			singel->updateDrones();
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


