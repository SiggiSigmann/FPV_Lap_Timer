#include "ScanForDrones.h"

ScanForDrones::ScanForDrones(Adafruit_SSD1306* d, Menu* m, Scanner* sc, DroneDetector* tracer):MenuList(d,m,4){
	this->scan = sc;
	this->tracker = tracer;
}

void ScanForDrones::draw(){
	//top
	this->display->fillRect(0,0,120,10,BLACK);
	this->display->setCursor(0,0);
	this->display->print("Scan For Drones: ");
	this->display->print(tracker->getNumberOfDrones());

	//menu
	byte idx = 0;
	drawPoint(idx++,"Scan");
	drawPoint(idx++,"Edit");
	drawPoint(idx++,"Denoise");
	drawPoint(idx++,"Reset");

	//graph
	this->display->drawLine(84,48,124,48,WHITE);
	this->display->setCursor(4,55);
	this->display->drawFastVLine(84,16,34,WHITE);
	this->display->drawFastVLine(124,16,34,WHITE);
	for(int i = 0; i<=40;i+=10){
		this->display->drawPixel(84+i,49,WHITE);
		this->display->drawPixel(84+i,50,WHITE);
	}

	//scann
	if(isScanning){
		byte level = scaleRSSI(scan->scanIdx(i), 32,scan->getMax());
		this->display->drawFastVLine((i+1)+84,8,40,BLACK);
		this->display->drawPixel((i)+84,48-level,WHITE);
		
		//push itterateor and stop if finised
		i++;
		if(i==40){
			isScanning = false;

			//execute detection
			tracker->setMeasurements(scan->getLastScan());
		}
	}else{
		i=0;
	}

	//draw drones
	byte* drones = tracker->getDroneFreqs();
	for(int j = 0; j<tracker->getNumberOfDrones();j++){
		//celar channelname
		this->display->fillRect(64,55,60,10,BLACK);

		if((j!=lineidx) || !edit){
			//only display if nothing will be moved or edit
			this->display->drawFastVLine(drones[j]+84,18,30,WHITE);
		}else{

			//draw Channelname
			this->display->setCursor(64,55);
			this->display->print(pgm_read_word_near(channelNames+drones[j]),HEX);

			//line blinks in different speed
			int towait = 1000;
			if(editline){
				towait = 200;

			}
			if(time + towait < millis()){
				time = millis();
				drawline = !drawline;
				this->display->drawFastVLine(drones[j]+84,18,30,BLACK);
				if(drawline){
					//draw line
					this->display->drawFastVLine(drones[j]+84,18,30,WHITE);
				}else{
					//if no line 0> draw point
					byte level = scaleRSSI(scan->getLastScan()[drones[j]], 32,scan->getMax());
					this->display->drawPixel((drones[j])+84,48-level,WHITE);
				}
			}
		}
	}

	if(scan->isDenoise()) tracker->setOffset(scan->getMaxNoise());
}

void ScanForDrones::buttonNext(){
	switch (activePoint){
		case 0:
			//scan for Drones
			tracker->reset();
			isScanning = true;
			break;
		
		case 1:
			//edit if there is someting
			if(tracker->getNumberOfDrones() >0){
				edit = true;
				activePoint = 4;
				time = millis();
			}
			break;
		case 2:
			//scan noise
			display->clearDisplay();
			display->setCursor(0,0);
			display->print("capture Noise");
			display->display();

			scan->captureNoise();
			tracker->setOffset(scan->getMaxNoise());
			break;
		case 3:
			//reset
			this->display->clearDisplay();
			tracker->reset();
			break;
		case 4:
			// a trick => switch between edit
			editline = !editline;
			break;
	}
}

void ScanForDrones::buttonUp(){
	if(!edit){
		//normal menu stuff
		if(this->activePoint ==0){
			this->activePoint= getNumberOfPoints()-1;
		}else{
			this->activePoint--;
		}
	}else{
		if(editline){
			//move line
			byte* drones = tracker->getDroneFreqs();
			byte level = scaleRSSI(scan->getLastScan()[drones[lineidx]], 32,scan->getMax());

			//remove old line
			this->display->drawFastVLine(drones[lineidx]+84,18,30,BLACK);
			this->display->drawPixel((drones[lineidx])+84,48-level,WHITE);

			//move
			if(drones[lineidx] == 0){
				drones[lineidx] = 39;
			}else{
				drones[lineidx]--;
			}

			
		}else{
			//choose line
			if(this->lineidx == 0){
				this->lineidx= tracker->getNumberOfDrones()-1;
			}else{
				this->lineidx--;
			}
		}

		//make line appear faster
		time = millis();
	}
}

void ScanForDrones::buttonDown(){
	if(!edit){
		//nomral menu stuff
		this->activePoint++;
		this->activePoint %=getNumberOfPoints();
	}else{
		if(editline){
			//move lines
			byte* drones = tracker->getDroneFreqs();
			byte level = scaleRSSI(scan->getLastScan()[drones[lineidx]], 32,scan->getMax());

			//remove old line
			this->display->drawFastVLine(drones[lineidx]+84,18,30,BLACK);
			this->display->drawPixel((drones[lineidx])+84,48-level,WHITE);

			drones[lineidx]++;
			drones[lineidx] %=40;
		}else{

			//select line
			this->lineidx++;
			this->lineidx %=  tracker->getNumberOfDrones();
		}

		//make line appear faster
		time = millis();
	}
}

void ScanForDrones::buttonPrev(){
	if(edit){
		if(editline){
			//stop moving the line
			editline = false;
		}else{
			//stop choosing a line
			edit = false;
			activePoint = 1;
			drawline = true;
		}
	}else{
		this->parent->acitvateMe();
	}
}