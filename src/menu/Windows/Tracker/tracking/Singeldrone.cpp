#include "Singeldrone.h"

Singeldrone::Singeldrone(Adafruit_SSD1306* d, Menu* m, Scanner* sc, LapTracker* tracer):MenuList(d,m,0){
	this->tracker = tracer;
	this->sc = sc;
}

void Singeldrone::draw(){
	//top
	this->display->fillRect(0,0,128,10,BLACK);
	this->display->setCursor(0,0);
	this->display->print("Single: ");
	this->display->print(i+1);
	this->display->print("/");
	this->display->print(tracker->getNumberOfDrones());
	this->display->print(" | ");
	this->display->print(millis()-last);
	last = millis();

	if(!windows){
		byte idx = 0;
		drawInfo(idx++,"FREQ: " + String(tracker->getDrones()[i].getFreq())+"|"+ String(tracker->getDrones()[i].getChannel(),HEX));
		drawInfo(idx++,"Noise: " + String(tracker->getDrones()[i].getNoiseLevel()));
		drawInfo(idx++,"Max: " + String(tracker->getDrones()[i].getMaxLevel()));
		drawInfo(idx++,"LastTime: " + String(tracker->getDrones()[i].getLastTime()));
	}else{
		//graph
		this->display->drawLine(84,48,124,48,WHITE);
		this->display->setCursor(4,55);
		this->display->drawFastVLine(84,16,34,WHITE);
		this->display->drawFastVLine(124,16,34,WHITE);
		for(byte idx = 0; idx<=40;idx+=10){
			this->display->drawPixel(84+idx,49,WHITE);
			this->display->drawPixel(84+idx,50,WHITE);
		}

		for(byte idx=0; idx<RSSIVALUEBUFFER;idx++){
			this->display->drawFastVLine((idx+1)+84,8,40,BLACK);

			byte level = scaleRSSI(tracker->getDrones()[i].getRSSI()[idx], 32, sc->getMax());
			this->display->drawPixel((idx)+84, 48-level, WHITE);
		}

		byte level = scaleRSSI(tracker->getDrones()[i].getThreshold(), 32, sc->getMax());
		this->display->drawFastHLine(84,48-level,48,WHITE);

		for(byte idx = 0; idx<4; idx++){
			drawInfo(idx,String(tracker->getDrones()[i].getLaps()[idx]),60);
		}
	}

	tracker->update();
}

void Singeldrone::buttonNext(){
	this->display->clearDisplay();
	windows = !windows;
}

void Singeldrone::buttonUp(){
	if(this->i ==0){
		this->i = tracker->getNumberOfDrones()-1;
	}else{
		this->i--;
	}
}

void Singeldrone::buttonDown(){
	i++;
	i %= tracker->getNumberOfDrones();
}
