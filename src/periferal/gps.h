#ifndef GPSSTUFF_H
#define GPSSTUFF_H

#include "Interfaces/GPSInterface.h"
#include "I2c/Communication.h"

class GPS : public GPSInterface{
	private:

	public:
		GPS();
		float* getPosition();
		byte getSatelites();
		String getTime();
		String getDate();
		void setTimeOffset(byte);

		void update();
};

extern GPS* gps;
#endif