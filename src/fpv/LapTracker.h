#ifndef LapTracker_H
#define LapTracker_H

#include "Drone.h"

#define MAXDRONENUMBER 8

class LapTracker{
	private:
		Drone drones[8];
		byte droneSize = 0;


	public:
		byte getNumberOfDrones();
		Drone* getDrones();

		void addDrone(int, int, int);
		void reset();
};

#endif