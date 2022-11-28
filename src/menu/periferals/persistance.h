#ifndef IPERSISTANCE_H
#define IPERSISTANCE_H

#include <Arduino.h>

class IPersistance{
	public:
		virtual bool isPrepared() = 0;

		virtual void storeSettings(String) = 0;
		virtual String readSettings() = 0;
};

#endif