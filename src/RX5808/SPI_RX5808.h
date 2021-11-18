#ifndef SPI_RX5808_H
#define SPI_RX5808_H

#include <Arduino.h>
#include "spi_pin.h"
#include "mySPI.h"

/**
 * SPI_RX5808 class
 */
class SPI_RX5808{
	private:
		byte* messange;							//messange buffer
		int rssiPin;
		unsigned long timeSinceChannel = 0;		//timestemp when channel was changed
		unsigned long valideTime = 30;  		// lower and there will be low spices in the rssi values
		int currentChannel = 0;					//store current channel to check if retune is needed
		MySPI* myspi;

		//methods to create and send messange to rx5805
		void sendData();
		void setAddress(short address);
		void setRW(boolean rw);
		void setPayload(long payload);

	public:
		SPI_RX5808(int);						//parameter = Analog pi for RSSI
		~SPI_RX5808();
		void setFreq(int);						//tune to frequenzy in parameter
		int getRSSI();							//get RSSi instance
		int getValideRSSI();					//get RSSI if valid (frequenzy tuned for 30 ms) otherwise get 0
		boolean isRSSIValid();					//get if rssi value is valid
		unsigned long getValideTime();			//get time since rssi is valied
		void setValideTime(unsigned long);		//set time to wait after frequenzy change so rssi value can sattel 
		void waitTillValid();					//blocks till rssi is valide
};

#endif 