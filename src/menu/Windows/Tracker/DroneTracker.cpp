#include "DroneTracker.h"

DroneTracker::DroneTracker(AbstractMenu* m):SubMenuList("DRONE TRACKER",m){
	multi = new Multidrone(this);
	singel = new Singeldrone(this);

	setExtra(String(droneDetector->getNumberOfDrones()));
}

void DroneTracker::drawMenu(){
	byte idx = 0;
	drawPoint("Load Drones");
	drawPoint("Singel view");
	drawPoint("Multi view");
	// drawPoint("Settings");

	lapTracker->update();
}

void DroneTracker::buttonNext(){
	byte* dr = droneDetector->getDroneFreqs();

	switch (activePoint){
		case 0:
			lapTracker->reset();
			for(int i =0;i<droneDetector->getNumberOfDrones();i++){
				lapTracker->addDrone(dr[i],scanner->getNoise()[dr[i]],scanner->getLastScan()[dr[i]]);
			}
			
			if(droneDetector->getNumberOfDrones()!=0){
				ok = true;
			}
			setExtra(String(droneDetector->getNumberOfDrones()));
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
				//trackersetings->acitvateMe();
			break;
	}
}


