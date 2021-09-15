#ifndef mySPI_H
#define mySPI_H

#include "spi_pin.h"
#include <ESP8266WiFi.h>

/**
 * 	MySPI calss, needed because spi and i2c (used for Diaplay) interfeare
 */
class MySPI{
	private:
		void inline sendBit(boolean bit);
	public:
		void begin();
		void transfer(byte); // transmit byte via spi
};




#endif