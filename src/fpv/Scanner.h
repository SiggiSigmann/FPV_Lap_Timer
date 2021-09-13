#ifndef SCANNER_H
#define SCANNER_H

#include "../RX5808/channels.h"
#include "../RX5808/SPI_RX5808.h"

class FPVScanner{
	private:
		int noise[40];
		int max=400;
		int* lastScann;
		boolean denoiced = false;
		SPI_RX5808* rx;

	public:
		FPVScanner(SPI_RX5808* rx);
		void scan(int[]);
		int scanIdx(short i);
		int* getLastScan();
		int getMax();
		void captureNoise();
		boolean isDenoiced();
};
	
#endif