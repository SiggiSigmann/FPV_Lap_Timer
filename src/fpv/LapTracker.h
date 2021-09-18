#ifndef LapTracker_H
#define LapTracker_H

#include "Drone.h"
#include "Scanner.h"

#define MAXDRONENUMBER 8

class LapTracker{
	private:
		Drone drones[8];
		byte droneSize = 0;
		Scanner* sc;


	public:
		LapTracker(Scanner*);
		byte getNumberOfDrones();
		Drone* getDrones();

		void addDrone(int, int, int);
		void reset();

		void update();
};

#endif