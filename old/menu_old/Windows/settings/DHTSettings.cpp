#include "DHTSettings.h"

DHTSettings::DHTSettings(GUI* m):Menu("DHT Settings",m){
}

void DHTSettings::drawMenu(){
	drawInfo("detected: " + String(dhtSensor->isDetected()));
	drawInfo("T: " + String(dhtSensor->getTemperature()));
	drawInfo("H: " + String(dhtSensor->getHumidity()));
}


void DHTSettings::buttonNext(){
	
}

