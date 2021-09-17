#include "DroneTracker.h"

DroneTracker::DroneTracker(Adafruit_SSD1306* d, Menu* m, Scanner* sc, LapTracker* tracer):MenuPoint(d,m){
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

	if(!exists){
		this->display->fillRect(4,18,8,8,BLACK);
		this->display->setCursor(18,18);
		this->display->drawRect(4,18,8,8,WHITE);
		this->display->print("load");
		this->display->fillRect(4,18,8,8,WHITE);
		
	}else{
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
			for(int j = 0;j<48;j++){
				this->display->drawLine(xVal+j, ((yVal*6)+16), xVal+j, ((yVal*6)+26),BLACK);
				byte level = scaleRSSI(drones[i].getRSSI()[j], 10, sc->getMax());
				this->display->drawPixel(xVal+j, ((yVal*6)+26)-level, WHITE);
			}
		}

		//add RSSI Value
		drones[isx].addRSSI(sc->scanFreq(drones[isx].getFreq()));

		//move droneiterator
		isx++;
		isx %= this->tracker->getNumberOfDrones();	
		
	}
	
}

void DroneTracker::buttonNext(){
	//create drone array
	if(this->tracker->getNumberOfDrones() == 0) return;
	if(!drones){
		delete [] drones;
	}
	drones = new Drone[this->tracker->getNumberOfDrones()];
	byte* dr = tracker->getDroneFreqs();
	for(int i =0;i<this->tracker->getNumberOfDrones();i++){
		drones[i].setFreq(pgm_read_word_near(channelFreqTable+pgm_read_word_near(channelList+ dr[i])));
		//drones[i].setNoiseLevel(sc->noiceAt(dr[i]));
		//drones[i].setMaxLevel(sc->getLastScanValue(dr[i]));

	}
	exists = true;
	this->display->fillRect(4,18,116,8,BLACK);
}

void DroneTracker::buttonUp(){
	
}

void DroneTracker::buttonDown(){
	
}

void DroneTracker::buttonPrev(){
	this->parent->acitvateMe();

	//delete drone array
	exists = false;
	if(!drones){
		delete [] drones;
	}
}

