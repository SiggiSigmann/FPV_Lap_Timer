#ifndef GPSINTERFACE_H
#define GPSINTERFACE_H

#include <Arduino.h>

class GPSInterface{

	public:
		virtual float* getPosition()  = 0;
		virtual byte getSatelites()  = 0;
		virtual String getTime()  = 0;
		virtual String getDate()  = 0;
		virtual void setTimeOffset(byte)  = 0;
		virtual void setTimeOffset(byte)  = 0;
		virtual void update() = 0;
};

#endif