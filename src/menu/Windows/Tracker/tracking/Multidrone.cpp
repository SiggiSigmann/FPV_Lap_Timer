#include "Multidrone.h"

Multidrone::Multidrone( AbstractMenu* m, Scanner* sc, LapTracker* tracer):MenuWindow("MULTI",m){
	this->tracker = tracer;
	this->sc = sc;

	setExtra(String(tracker->getNumberOfDrones()));
}

void Multidrone::draw(){
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

		display.drawRect(xVal,(yVal*6)+16,10,10,WHITE);
		xVal += 2;
		display.setCursor(xVal,(yVal*6)+18);
		display.print(i);
		xVal += 10;

		if(showtimes){
			display.fillRect(xVal, ((yVal*6)+16), xVal+42, ((yVal*6)+26),BLACK);
			display.setCursor(xVal,(yVal*6)+18);
			display.print(tracker->getDrones()[i].getBest());
		}else{
			for(int j = 0;j<RSSIVALUEBUFFER;j++){
				display.drawLine(xVal+j, ((yVal*6)+16), xVal+j, ((yVal*6)+26),BLACK);
				byte level = scaleRSSI(tracker->getDrones()[i].getRSSI()[j], 10, sc->getMax());
				display.drawPixel(xVal+j, ((yVal*6)+26)-level, WHITE);
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