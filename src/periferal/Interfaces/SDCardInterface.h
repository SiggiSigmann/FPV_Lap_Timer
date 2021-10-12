#ifndef SDCARDINTERFACE_H
#define SDCARDINTERFACE_H

#include <Arduino.h>

class SDCardInterface{

	public:
		virtual byte start()  = 0;
		virtual int getSize()  = 0;
		virtual int getFreeSpace()  = 0;
		virtual byte createNewLogFile() = 0;
		virtual byte writeToLogFile(String)  = 0;

		virtual int storeTrack(float**, int, byte)  = 0;
		virtual float** getTrack(byte)  = 0;

		virtual int storeTrackImage(byte[], int, byte)  = 0;
		virtual byte* getTrackImage(byte)  = 0;
};

#endif