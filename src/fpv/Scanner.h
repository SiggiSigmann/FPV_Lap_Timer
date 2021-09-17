#ifndef SCANNER_H
#define SCANNER_H

#include "../RX5808/channels.h"
#include "../RX5808/SPI_RX5808.h"

class FPVScanner{
	private:
		int noise[40];
		int* measurement;
		int max=200;
		int maxNoice = 200;
		boolean denoiced = false;
		SPI_RX5808* rx;

	public:
		FPVScanner(SPI_RX5808* rx);
		void scan();
		int scanIdx(short i);
		int scanFreq(short i);
		int* getLastScan();
		int getLastScanValue(byte);
		int getMax();
		void captureNoise();
		void resetNoise();
		boolean isDenoiced();
		int getMaxNoice();
		int noiceAt(byte i);
};
	
#endif