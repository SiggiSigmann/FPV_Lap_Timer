#include "Singeldrone.h"

Singeldrone::Singeldrone(AbstractMenu* m, Scanner* sc, LapTracker* tracer):SubMenuList("SINGEL",m,0){
	this->tracker = tracer;
	this->sc = sc;

	setExtra(String(i)+"/"+String(tracker->getNumberOfDrones()));
}

void Singeldrone::draw(){
	if(!windows){
		byte idx = 0;
		drawInfo(idx++,"FREQ: " + String(tracker->getDrones()[i].getFreq())+"|"+ String(tracker->getDrones()[i].getChannel(),HEX));
		drawInfo(idx++,"Noise: " + String(tracker->getDrones()[i].getNoiseLevel()));
		drawInfo(idx++,"Max: " + String(tracker->getDrones()[i].getMaxLevel()));
		drawInfo(idx++,"Best: " + String(tracker->getDrones()[i].getBest()));
	}else{
		//graph
		display.drawLine(84,48,124,48,WHITE);
		display.setCursor(4,55);
		display.drawFastVLine(84,16,34,WHITE);
		display.drawFastVLine(124,16,34,WHITE);
		for(byte idx = 0; idx<=40;idx+=10){
			display.drawPixel(84+idx,49,WHITE);
			display.drawPixel(84+idx,50,WHITE);
		}

		for(byte idx=0; idx<RSSIVALUEBUFFER;idx++){
			display.drawFastVLine((idx+1)+84,8,40,BLACK);

			byte level = scaleRSSI(tracker->getDrones()[i].getRSSI()[idx], 32, sc->getMax());
			display.drawPixel((idx)+84, 48-level, WHITE);
		}

		//draw upperlimit
		byte level = scaleRSSI(tracker->getDrones()[i].getUpper(), 32, sc->getMax());
		display.drawFastHLine(84,48-level,48,WHITE);
		
		//drow bottumlimit
		level = scaleRSSI(tracker->getDrones()[i].getLower(), 32, sc->getMax());
		display.drawFastHLine(84,48-level,48,WHITE);

		for(byte idx = 0; idx<4; idx++){
			drawInfo(idx,String(tracker->getDrones()[i].getLaps()[idx]),60);
		}

		display.fillRect(64,55,20,10,BLACK);
		if(tracker->getDrones()[i].getFareAway()){
			display.setCursor(64,55);
			display.print("far");
		}
	}

	tracker->update();
}

void Singeldrone::buttonNext(){
	display.clearDisplay();
	windows = !windows;
}

void Singeldrone::buttonUp(){
	if(this->i ==0){
		this->i = tracker->getNumberOfDrones()-1;
	}else{
		this->i--;
	}
	setExtra(String(i)+"/"+String(tracker->getNumberOfDrones()));
}

void Singeldrone::buttonDown(){
	i++;
	i %= tracker->getNumberOfDrones();
	setExtra(String(i)+"/"+String(tracker->getNumberOfDrones()));
}
