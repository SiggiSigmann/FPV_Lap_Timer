#include "DroneTracker.h"

DroneTracker::DroneTracker(Adafruit_SSD1306* d, Menu* m, Scanner* sc, DroneDetector* tracer):MenuList(d,m,3){
	this->sc = sc;
	this->tracker = tracer;
}

void DroneTracker::draw(){
	//top
	this->display->fillRect(0,0,128,10,BLACK);
	this->display->setCursor(0,0);
	this->display->print("Drone Tracker:");
	this->display->print(tracker->getNumberOfDrones());
	this->display->print("|");
	this->display->print(millis()-last);
	last = millis();

	byte idx = 0;
	drawPoint(idx++,"Load Drones");
	drawPoint(idx++,"Singel view");
	drawPoint(idx++,"Singel view");

	//if(!exists){
		this->display->fillRect(4,18,8,8,BLACK);
		this->display->setCursor(18,18);
		this->display->drawRect(4,18,8,8,WHITE);
		this->display->print("load");
		this->display->fillRect(4,18,8,8,WHITE);
		
	/*}else{
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
				this->display->print(drones[i].getLastTime());
			}else{
				for(int j = 0;j<RSSIVALUEBUFFER;j++){
					this->display->drawLine(xVal+j, ((yVal*6)+16), xVal+j, ((yVal*6)+26),BLACK);
					byte level = scaleRSSI(drones[i].getRSSI()[j], 10, sc->getMax());
					this->display->drawPixel(xVal+j, ((yVal*6)+26)-level, WHITE);
				}
			}

		}*/

	if(!drones){
		//add RSSI Value
		int val = sc->scanFreq(drones[isx].getFreq());
		drones[isx].addRSSI(val);

		//move droneiterator
		isx++;
		isx %= this->tracker->getNumberOfDrones();	
	}
}

void DroneTracker::buttonNext(){
	switch (activePoint){
		case 0:
			if(!drones){
				delete [] drones;
			}
			drones = new Drone[this->tracker->getNumberOfDrones()];
			byte* dr = tracker->getDroneFreqs();
			for(int i =0;i<this->tracker->getNumberOfDrones();i++){
				drones[i].setFreq(pgm_read_word_near(channelFreqTable+dr[i]));
				drones[i].setNoiseLevel(sc->getNoise()[dr[i]]);
				drones[i].setMaxLevel(sc->getLastScan()[dr[i]]);
			}
			break;
			
		/*case 1:

			break;

		case 2:
		
			break;*/
	}
	/*//create drone array
	if(this->tracker->getNumberOfDrones() == 0) return;
	
	exists = true;
	this->display->fillRect(4,18,116,8,BLACK);*/
}

void DroneTracker::buttonUp(){
	//showtimes = !showtimes;
}

void DroneTracker::buttonDown(){
	//showtimes = !showtimes;
}

void DroneTracker::buttonPrev(){
	this->parent->acitvateMe();

	//delete drone array
	//exists = false;
	if(!drones){
		delete [] drones;
	}
}

