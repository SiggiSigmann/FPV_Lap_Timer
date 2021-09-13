#include "Selection.h"

Selection::Selection(Adafruit_SSD1306* d, Menu* m, FPVScanner* sc):MenuPoint(d,m){
	osci = new Osciloskope(d, this, sc);
	rssi = new RSSIMeter(d, this, sc);
	this->scan = sc;
}

void Selection::draw(){
	this->display->fillRect(10,20,10,10,BLACK);
	this->display->fillRect(10,40,10,10,BLACK);


	this->display->setCursor(20,20);
	this->display->print("OSCI");
	if(activePoint == 0){
		this->display->drawRect(10,20,10,10,WHITE);
	}


	this->display->setCursor(20,40);
	this->display->print("RSSI");
	if(activePoint == 1){
		this->display->drawRect(10,40,10,10,WHITE);
	}

	this->display->display();
}	

void Selection::processButton(){
	if(digitalRead(4)){
		activePoint++;
		activePoint %=2;
	}
	if(digitalRead(5)){
		if(activePoint == 0){
			osci->acitvateMe();
		}else{
			rssi->acitvateMe();
		}
	}
}