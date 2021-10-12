#ifndef GPSINTERFACE_H
#define GPSINTERFACE_H

#include <Arduino.h>

class GPSInterface{

	public:
		virtual float* getPosition();
		virtual byte getSatelites();
		virtual int getTime();
		virtual int getDate();
		virtual void setTimeOffset(byte);
};

#endif