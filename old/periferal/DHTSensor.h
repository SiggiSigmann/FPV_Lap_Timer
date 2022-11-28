#ifndef DHTSENSOR_H
#define DHTSENSOR_H

#include <DHT.h>
//#include <Adafruit_Sensor.h>

#define DHT_TYPE DHT11

class DHTSensor{
	private:
		DHT* dht;
		bool detected = false;

	public:
		DHTSensor();
		float getTemperature();
		float getHumidity();
		bool isDetected();
};

extern DHTSensor* dhtSensor;

#endif