#include "DHTSettings.h"

DHTSettings::DHTSettings():Menu("DHT Settings"){
	this->addEntry(MenuEntry{"detected: " + String(dhtSensor->isDetected()),1,0});
	this->addEntry(MenuEntry{"T: " + String(dhtSensor->getTemperature()),1,1});
	this->addEntry(MenuEntry{"H: " + String(dhtSensor->getHumidity()),1,2});
}



//actions before and after
void DHTSettings::preActions(){};
void DHTSettings::postActions(){};

void DHTSettings::buttonAction(byte){};

void DHTSettings::menuDraw(){
	this->updateAll();
}


String DHTSettings::updateEntry(byte id){
	switch (id){
		case 0: return "detected: " + String(dhtSensor->isDetected());
		case 1: return "T: " + String(dhtSensor->getTemperature());
		case 2: return "H: " + String(dhtSensor->getHumidity());
		
		default: return "";
	}
}