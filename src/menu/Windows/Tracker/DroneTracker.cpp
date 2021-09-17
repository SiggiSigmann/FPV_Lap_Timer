#include "DroneTracker.h"

DroneTracker::DroneTracker(Adafruit_SSD1306* d, Menu* m, FPVScanner* sc, LapTracker* tracer):MenuPoint(d,m){
	this->sc = sc;
	this->tracker = tracer;
}

void DroneTracker::draw(){
	this->display->fillRect(0,0,128,10,BLACK);
	this->display->setCursor(0,0);
	this->display->print("Drone Tracker:");
	this->display->print(tracker->getNumberOfDrones());
	this->display->print("|");
	this->display->print(millis()-last);
	last = millis();

	int x = 18;

	if(!exists){
		this->display->fillRect(4,x,8,8,BLACK);
		this->display->setCursor(18,x);
		this->display->drawRect(4,x,8,8,WHITE);
		this->display->print("load");
		if(activePoint == 0){
			this->display->fillRect(4,x,8,8,WHITE);
		}
	}else{
		this->display->fillRect(4,x,116,8,BLACK);
	

	if(this->tracker->getNumberOfDrones()){
		for(int i=0;i<this->tracker->getNumberOfDrones();i++){

			if(i & 0x1){
				this->display->drawRect(65,((i-1)*6)+16,10,10,WHITE);
				this->display->setCursor(67,((i-1)*6)+18);
				this->display->print(i);
				for(int j = 0;j<48;j++){
					this->display->drawLine(77+j,(((i-1)*6)+16),77+j,(((i-1)*6)+26),BLACK);
					float level = (float)  drones[i].getRSSI(j) / (float)sc->getMax();
					level *= 10;
					this->display->drawPixel(77+j,(((i-1)*6)+26)-level,WHITE);
				}
			}else{

				this->display->drawRect(4,(i*6)+16,10,10,WHITE);
				this->display->setCursor(6,(i*6)+18);
				this->display->print(i);
				for(int j = 0;j<48;j++){
					this->display->drawLine(16+j,(((i)*6)+16),16+j,(((i)*6)+26),BLACK);
					float level = (float)drones[i].getRSSI(j) / (float)sc->getMax();
					level *= 10;
					this->display->drawPixel(16+j,(((i)*6)+26)-level,WHITE);
				}
			}
		}
	}

	if(this->tracker->getNumberOfDrones()){
		drones[isx].addRSSI(sc->scanFreq(drones[isx].getFreq()));

		isx++;
		isx %= this->tracker->getNumberOfDrones();	
	}
	}
	
}

void DroneTracker::buttonNext(){
	if(this->tracker->getNumberOfDrones() == 0) return;
	if(!drones){
		delete [] drones;
	}
	drones = new Drone[this->tracker->getNumberOfDrones()];
	byte* dr = tracker->getDroneFreqs();
	for(int i =0;i<this->tracker->getNumberOfDrones();i++){
		drones[i].setFreq(pgm_read_word_near(channelFreqTable+pgm_read_word_near(channelList+ dr[i])));
		drones[i].setNoiseLevel(sc->noiceAt(dr[i]));
		drones[i].setMaxLevel(sc->getLastScanValue(dr[i]));

	}
	exists = true;
}

void DroneTracker::buttonUp(){
	
}

void DroneTracker::buttonDown(){
	
}

void DroneTracker::buttonPrev(){
	this->parent->acitvateMe();
	exists = false;
	if(!drones){
		delete [] drones;
	}
}

