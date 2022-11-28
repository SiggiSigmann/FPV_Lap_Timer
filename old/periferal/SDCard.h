#ifndef SDCARD_H
#define SDCARD_H

#include <arduino.h>
#include <SPI.h>
#include <SD.h>
#include "../menu/utils/Toast.h"

class SDCard {
	private:
		bool sdCardExistsLastTime = false;
		bool initSDCard();
		bool isInit = false;
		SDFS* sd = &SD;
		String cardType="";
		uint64_t cardSize=0;
		size_t numSectors=0;
		size_t sectorSize=0;
		uint64_t totalBytes=0;
		uint64_t usedBytes=0;
		int numberOfTracks=0;
		int numberOfLaps=0;
		String currentFile="";
	public:
		SDCard();
		void update();
		void clean();
		void initialize();
		bool getInit();

		bool sdCardExists();
		String getCardType();
		uint64_t getCardSize();
		size_t getNumSectors();
		size_t getSectorSize();
		uint64_t getTotalBytes();
		uint64_t getUsedBytes();
		int getNumberOfTracks();
		int getNumberOfLaps();
		String getCurrentFile();

		void generateNewFile();
		void appendToNewFile(String);

		bool doesFileExists(String);
		String readFile(String);

};

extern SDCard* sdCard;
#endif