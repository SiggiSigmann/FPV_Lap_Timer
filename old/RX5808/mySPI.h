#ifndef mySPI_H
#define mySPI_H

#include "spi_pin.h"
#include <Arduino.h>

/**
 * 	MySPI calss, needed because spi and i2c (used for Diaplay) interfeare
 */
class MySPI{
	private:
		void inline sendBit(boolean bit);	//send a Bit
	public:
		void begin();						//init pins
		void transfer(byte); 				// transmit byte via spi
};

#endif