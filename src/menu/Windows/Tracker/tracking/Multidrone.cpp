#include "Multidrone.h"

Multidrone::Multidrone(Window* m):MenuWindow("MULTI",m){
	setExtraInfromation(String(lapTracker->getNumberOfDrones()) + " " + String(timeForOneScan));
	
}

void Multidrone::draw(){
	setExtraInfromation(String(lapTracker->getNumberOfDrones()) + " " + String(timeForOneScan));
	//for all existing drones
	for(byte i=0;i<lapTracker->getNumberOfDrones();i++){
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
			display.print(lapTracker->getDrones()[i].getBest());
		}else{
			for(int j = 0;j<RSSIVALUEBUFFER;j++){
				display.drawLine(xVal+j, ((yVal*6)+16), xVal+j, ((yVal*6)+26),BLACK);
				byte level = scaleRSSI(lapTracker->getDrones()[i].getRSSI()[j], 10, scanner->getMax());
				display.drawPixel(xVal+j, ((yVal*6)+26)-level, WHITE);
			}
		}

	}
}

void Multidrone::buttonNext(){
}


void Multidrone::buttonUp(){
	showtimes = !showtimes;
}
void Multidrone::buttonDown(){
	showtimes = !showtimes;
}

void Multidrone::updateDrones(){
	setExtraInfromation(String(lapTracker->getNumberOfDrones()) + " " + String(timeForOneScan));
}