#include "ScanForDrones.h"

ScanForDrones::ScanForDrones(Adafruit_SSD1306* d, AbstractMenu* m, Scanner* sc, DroneDetector* tracer):SubMenuList("SCAN FOR DRONES",d,m,4){
	this->scan = sc;
	this->detector = tracer;
	this->setExtra("0");
}

void ScanForDrones::draw(){
	//menu
	byte idx = 0;
	drawPoint(idx++,"Scan", 70);
	drawPoint(idx++,"Edit",70);
	drawPoint(idx++,"Denoise",70);
	drawPoint(idx++,"Reset",70);

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
			detector->setMeasurements(scan->getLastScan());
			this->setExtra(String(detector->getNumberOfDrones()));
		}
	}else{
		i=0;
	}

	//celar channelname
	this->display->fillRect(64,55,60,10,BLACK);

	//draw drones
	byte* drones = detector->getDroneFreqs();
	for(int j = 0; j<detector->getNumberOfDrones();j++){

		if((j!=lineidx) || !edit){
			//only display if nothing will be moved or edit
			this->display->drawFastVLine(drones[j]+84,18,30,WHITE);
		}else{
			//line blinks in different speed
			int towait = 1000;
			if(editline){
				towait = 200;

			}

			if(j==lineidx){
				//draw Channelname
				this->display->setCursor(64,55);
				this->display->print(pgm_read_word_near(channelNames + pgm_read_word_near(channelList + drones[lineidx]) ),HEX);
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

	if(scan->isDenoise()) detector->setOffset(scan->getMax()/2);
}

void ScanForDrones::buttonNext(){
	switch (activePoint){
		case 0:
			//scan for Drones
			detector->reset();
			isScanning = true;
			break;
		
		case 1:
			//edit if there is someting
			if(detector->getNumberOfDrones() >0){
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
			//detector->setOffset(scan->getMaxNoise());
			break;
		case 3:
			//reset
			this->display->clearDisplay();
			detector->reset();
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
		/*if(this->activePoint ==0){
			this->activePoint= getNumberOfPoints()-1;
		}else{
			this->activePoint--;
		}*/
		SubMenuList::buttonUp();
	}else{
		if(editline){
			//move line
			byte* drones = detector->getDroneFreqs();
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
				this->lineidx= detector->getNumberOfDrones()-1;
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
		SubMenuList::buttonDown();
		//this->activePoint++;
		//this->activePoint %=getNumberOfPoints();
	}else{
		if(editline){
			//move lines
			byte* drones = detector->getDroneFreqs();
			byte level = scaleRSSI(scan->getLastScan()[drones[lineidx]], 32,scan->getMax());

			//remove old line
			this->display->drawFastVLine(drones[lineidx]+84,18,30,BLACK);
			this->display->drawPixel((drones[lineidx])+84,48-level,WHITE);

			drones[lineidx]++;
			drones[lineidx] %=40;
		}else{

			//select line
			this->lineidx++;
			this->lineidx %=  detector->getNumberOfDrones();
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