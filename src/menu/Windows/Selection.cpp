#include "Selection.h"

Selection::Selection(Adafruit_SSD1306* d, Menu* m, FPVScanner* sc):MenuPoint(d,m){
	osci = new Osciloskope(d, this, sc);
	rssi = new RSSIMeter(d, this, sc);
	this->scan = sc;
}

void Selection::draw(){
	this->display->setCursor(0,0);
	this->display->fillRect(0,0,120,6,BLACK);
	this->display->print(millis());

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
}	

void Selection::buttonNext(){
	if(activePoint == 0){
		osci->acitvateMe();
	}else{
		rssi->acitvateMe();
	}
}
void Selection::buttonUp(){
	activePoint--;
	activePoint %=2;
}
void Selection::buttonDown(){
	activePoint++;
	activePoint %=2;
}