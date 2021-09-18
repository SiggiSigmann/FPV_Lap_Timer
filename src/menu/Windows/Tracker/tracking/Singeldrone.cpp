#include "Singeldrone.h"

Singeldrone::Singeldrone(Adafruit_SSD1306* d, Menu* m, Scanner* sc, LapTracker* tracer):MenuPoint(d,m){
	this->tracker = tracer;
	this->sc = sc;
}

void Singeldrone::draw(){
	//top
	this->display->fillRect(0,0,128,10,BLACK);
	this->display->setCursor(0,0);
	this->display->print("Single Drone:");
	this->display->print(tracker->getNumberOfDrones());
	this->display->print("|");
	this->display->print(millis()-last);
	last = millis();

	tracker->update();
}

void Singeldrone::buttonNext(){
}

		void Singeldrone::buttonUp(){}
		void Singeldrone::buttonDown(){}
