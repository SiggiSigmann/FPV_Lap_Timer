#ifndef GPSSTUFF_H
#define GPSSTUFF_H

#include "Interfaces/GPSInterface.h"
#include <TinyGPS++.h>

class GPS : public GPSInterface{
	private:
		boolean sommertime = false;
		int timezone = 0;
		byte minSat = 5;

		TinyGPSPlus gpsEncoder = TinyGPSPlus();

	public:
		GPS();
		float* getPosition();
		byte getSatelites();
		String getTime();
		String getDate();
		void setTimeOffset(int);
		void update();

		boolean getSommerTime();
		void setSommerTime(boolean);

		int getTimeSzone();
		void setTimeSzone(int);
		boolean isValid();

		byte getMinSat();
		void setMinSat(byte);
};

extern GPS* gps;
#endif