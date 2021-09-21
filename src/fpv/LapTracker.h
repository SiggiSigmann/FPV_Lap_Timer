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
		byte upperpercentage = 90;
		byte lowerpercentage = 60;

		boolean detectLap();

	public:
		LapTracker(Scanner*);
		byte getNumberOfDrones();
		Drone* getDrones();

		void addDrone(byte, int, int);
		void reset();

		void update();

		boolean detectLap(byte i);

		byte getUpper();
		void setUpper(byte);

		byte getLower();
		void setLower(byte);

		void resetTimes();

};

#endif