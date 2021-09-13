#include "Osciloskope.h"


Osciloskope::Osciloskope(Adafruit_SSD1306* d, Menu* parent):MenuPoint(d){
	Serial.println("huaa");
}

void Osciloskope::draw(){
	this->display->drawLine(4,48,124,48,WHITE);
	this->display->setCursor(4,50);
	this->display->print("5645");
	this->display->setCursor(102,50);
	this->display->print("5945");
	this->display->display();
}

void Osciloskope::processButton(){

}

