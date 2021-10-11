#ifndef LapTracker_H
#define LapTracker_H

#include "Drone.h"
#include "Scanner.h"
#include "../util/sdcard.h"
#include "Scanner.h"

#define MAXDRONENUMBER 8

TaskHandle_t xHandle = NULL;

class LapTracker{
	private:
		Drone drones[8];
		byte droneSize = 0;
		byte upperpercentage = 85;
		byte lowerpercentage = 75;

		TaskHandle_t NamedesTaskhadle; 

		boolean detectLap();

	public:
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

		void startThread();
		void stopThread();

};

extern  LapTracker* lapTracker;

#endif