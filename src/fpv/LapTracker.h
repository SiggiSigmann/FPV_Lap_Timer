#ifndef LapTracker_H
#define LapTracker_H

#include "RX5808/channels.h"
#include "RX5808/SPI_RX5808.h"

class LapTracker{
	private:
		int* measurevalues;
		short scannPM = 8;
		int strengthoffset = 200;
		//boolean denoiced;
		byte drones[10];
		byte numberOfDrones=0;


	public:
		void setMeasurements(int*);
		//void setDenoiced(short);
		short getNumberOfDrones();
		byte* getDroneFreqs();
		void setMaxOffset(int);
		void reset();
};

#endif