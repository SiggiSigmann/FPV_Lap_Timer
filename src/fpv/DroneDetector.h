#ifndef DRONEDETECTOR_H
#define DRONEDETECTOR_H

#include "RX5808/channels.h"
#include "RX5808/SPI_RX5808.h"

#define MAXDRONENUMBER 8

class DroneDetector{
	private:
		int* measurevalues;				//pointer to rssivalues to scan in shpuld be CHANNELAMOUT long
		int strengthoffset = 200;		//offset for values to be ignored if they are smaler
		short scannPM = 8;				//number of chanels left and right where the rssi value has to be smaler
		
		//store detected drones
		byte drones[MAXDRONENUMBER];
		byte numberOfDrones=0;


	public:
		void setMeasurements(int*);
		short getNumberOfDrones();
		byte* getDroneFreqs();
		void setOffset(int);
		void reset();
		void addDrone();
		void deleteDrone(byte);

		//getter and setter for scannPM
		int getScannPM();
		void setScannPM(int);
};

extern  DroneDetector* droneDetector;

#endif