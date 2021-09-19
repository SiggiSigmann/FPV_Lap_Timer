#include "Multidrone.h"

Multidrone::Multidrone(Adafruit_SSD1306* d, Menu* m, Scanner* sc, LapTracker* tracer):MenuPoint(d,m){
	this->tracker = tracer;
	this->sc = sc;
}

void Multidrone::draw(){
	//top
	this->display->fillRect(0,0,128,10,BLACK);
	this->display->setCursor(0,0);
	this->display->print("Multi: ");
	this->display->print(tracker->getNumberOfDrones());
	this->display->print("|");
	this->display->print(millis()-last);
	last = millis();

	
	//for all existing drones
	for(byte i=0;i<this->tracker->getNumberOfDrones();i++){
		byte xVal = 0;
		byte yVal = 0;

		if(i & 0x1){
			yVal = i-1;
			xVal = 65;
		}else{
			yVal = i;
			xVal = 4;
		}

		this->display->drawRect(xVal,(yVal*6)+16,10,10,WHITE);
		xVal += 2;
		this->display->setCursor(xVal,(yVal*6)+18);
		this->display->print(i);
		xVal += 10;

		if(showtimes){
			this->display->fillRect(xVal, ((yVal*6)+16), xVal+42, ((yVal*6)+26),BLACK);
			this->display->setCursor(xVal,(yVal*6)+18);
			this->display->print(tracker->getDrones()[i].getLastTime());
		}else{
			for(int j = 0;j<RSSIVALUEBUFFER;j++){
				this->display->drawLine(xVal+j, ((yVal*6)+16), xVal+j, ((yVal*6)+26),BLACK);
				byte level = scaleRSSI(tracker->getDrones()[i].getRSSI()[j], 10, sc->getMax());
				this->display->drawPixel(xVal+j, ((yVal*6)+26)-level, WHITE);
			}
		}

	}


	tracker->update();
}

void Multidrone::buttonNext(){
}


void Multidrone::buttonUp(){
	showtimes = !showtimes;
}
void Multidrone::buttonDown(){
	showtimes = !showtimes;
}