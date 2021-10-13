#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <Arduino.h>
#include <Wire.h>

class SerialCommunication{
	private:
		float res[2] = {-1,-1};

	public:
		SerialCommunication();
		String getString(String);
		int getInt(String);
		float* getFloatArray2(String);
		byte getByte(String);
		void flush();
};

extern SerialCommunication* communication;

#endif