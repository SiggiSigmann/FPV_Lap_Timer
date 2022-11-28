#ifndef GPSINTERFACE_H
#define GPSINTERFACE_H

#include <Arduino.h>

class GPSInterface{

	public:
		virtual void getPosition(float*)  = 0;
		virtual byte getSatelites()  = 0;
		virtual String getTime()  = 0;
		virtual String getDate()  = 0;
		virtual void setTimeOffset(int)  = 0;
		virtual void update() = 0;

		virtual boolean isValid() = 0;
};

#endif