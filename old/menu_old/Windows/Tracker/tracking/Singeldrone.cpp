#include "Singeldrone.h"

Singeldrone::Singeldrone(GUI* m):Menu("SINGEL",m){
	setExtraInfromation(String(i)+"/"+String(lapTracker->getNumberOfDrones()) + " " + String(timeForOneScan));

}

void Singeldrone::drawMenu(){
	setExtraInfromation(String(i)+"/"+String(lapTracker->getNumberOfDrones()) + " " + String(timeForOneScan));
	if(!windows){
		drawInfo("FREQ: " + String(lapTracker->getDrones()[i].getFreq())+"|"+ String(lapTracker->getDrones()[i].getChannel(),HEX));
		drawInfo("Noise: " + String(lapTracker->getDrones()[i].getNoiseLevel()));
		drawInfo("Max: " + String(lapTracker->getDrones()[i].getMaxLevel()));
		drawInfo("Best: " + String(lapTracker->getDrones()[i].getBest()));
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

			byte level = scaleRSSI(lapTracker->getDrones()[i].getRSSI()[idx], 32, scanner->getMax());
			display.drawPixel((idx)+84, 48-level, WHITE);
		}

		//draw upperlimit
		byte level = scaleRSSI(lapTracker->getDrones()[i].getUpper(), 32, scanner->getMax());
		display.drawFastHLine(84,48-level,48,WHITE);
		
		//drow bottumlimit
		level = scaleRSSI(lapTracker->getDrones()[i].getLower(), 32, scanner->getMax());
		display.drawFastHLine(84,48-level,48,WHITE);

		for(byte idx = 0; idx<4; idx++){
			drawInfo(String(lapTracker->getDrones()[i].getLaps()[idx]),60);
		}

		display.fillRect(64,55,20,10,BLACK);
		if(lapTracker->getDrones()[i].getFareAway()){
			display.setCursor(64,55);
			display.print("far");
		}
	}
}

void Singeldrone::buttonNext(){
	display.clearDisplay();
	windows = !windows;
}

void Singeldrone::buttonUp(){
	if(this->i ==0){
		this->i = lapTracker->getNumberOfDrones()-1;
	}else{
		this->i--;
	}
	setExtraInfromation(String(i)+"/"+String(lapTracker->getNumberOfDrones()) + " " + String(timeForOneScan));
}

void Singeldrone::buttonDown(){
	i++;
	i %= lapTracker->getNumberOfDrones();
	setExtraInfromation(String(i)+"/"+String(lapTracker->getNumberOfDrones()) + " " + String(timeForOneScan));
}

void Singeldrone::updateDrones(){
	setExtraInfromation(String(i)+"/"+String(lapTracker->getNumberOfDrones()) + " " + String(timeForOneScan));
}
