#include "DHTSensor.h"

DHTSensor::DHTSensor(){
	this->dht = new DHT(32, DHT11);
	this->dht->begin();
	float temp = this->dht->readTemperature();
	if (temp == temp) {
		this->detected = true;
	} else {
		this->detected = false;
	}
}

float DHTSensor::getTemperature(){
	float temp = this->dht->readTemperature();
	if (temp == temp) {
		this->detected = true;
		return temp;
	} else {
		this->detected = false;
		return -1;
	}
}

float DHTSensor::getHumidity(){
	float hum = this->dht->readHumidity();
		if (hum == hum) {
		this->detected = true;
		return hum;
	} else {
		this->detected = false;
		return -1;
	}
}

bool DHTSensor::isDetected(){
	return this->detected;
}
