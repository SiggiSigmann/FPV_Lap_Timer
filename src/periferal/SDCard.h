#ifndef SDCARD_H
#define SDCARD_H

#include <arduino.h>
#include <SPI.h>
#include <SD.h>

class SDCard {
	private:
		boolean sdCardExistsLastTime = false;
		boolean initSDCard();
		boolean isInit = false;
		SDFS* sd = &SD;
		String cardType="";
		uint64_t cardSize=0;
		size_t numSectors=0;
		size_t sectorSize=0;
		uint64_t totalBytes=0;
		uint64_t usedBytes=0;
		int numberOfTracks=0;
		int numberOfLaps=0;
	public:
		SDCard();
		void update();

		boolean sdCardExists();
		boolean getInit();
		String getCardType();
		uint64_t getCardSize();
		size_t getNumSectors();
		size_t getSectorSize();
		uint64_t getTotalBytes();
		uint64_t getUsedBytes();
		int getNumberOfTracks();
		int getNumberOfLaps();
		void clean();
		void initialize();
};
/*
*/

extern SDCard* sdCard;

#endif