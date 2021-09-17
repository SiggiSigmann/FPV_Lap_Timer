#ifndef SCANNER_H
#define SCANNER_H

#include "../RX5808/channels.h"
#include "../RX5808/SPI_RX5808.h"

class Scanner{
	private:
		//used to capture and subtrac noise.
		int noise[CHANNELAMOUT] = {0};				//orderd by frequenzy
		int maxNoise = 200;
		boolean denoised = false;

		//used to store last measurements
		int measurement[CHANNELAMOUT] = {0};		//orderd as frequenzy
		int max=200;
		
		SPI_RX5808* rx;

	public:
		Scanner(SPI_RX5808* rx);

		//noice
		void captureNoise();
		void resetNoise();
		boolean isDenoise();
		int getMaxNoise();
		int* getNoise();

		//measurements
		void scan();
		int scanIdx(byte i);
		int scanFreq(int i);
		int* getLastScan();
		int getMax();
};
	
#endif