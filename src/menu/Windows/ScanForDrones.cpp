#include "ScanForDrones.h"

ScanForDrones::ScanForDrones(Adafruit_SSD1306* d, Menu* m, FPVScanner* sc ):MenuPoint(d,m){
	this->sc = sc;
	tracker = new LapTracker();
}

void ScanForDrones::draw(){
	this->display->fillRect(0,0,120,10,BLACK);
	this->display->setCursor(0,0);
	this->display->print("ScanForDrones:");
	this->display->print(tracker->getNumberOfDrones());

	byte x = 18;

	this->display->fillRect(4,x,8,8,BLACK);
	this->display->setCursor(18,x);
	this->display->drawRect(4,x,8,8,WHITE);
	this->display->print("Scann");
	if(activePoint == 0){
		this->display->fillRect(4,x,8,8,WHITE);
	}

	x +=12;
	this->display->fillRect(4,x,8,8,BLACK);
	this->display->setCursor(18,x);
	this->display->drawRect(4,x,8,8,WHITE);
	this->display->print("edit");
	if(activePoint == 1){
		this->display->fillRect(4,x,8,8,WHITE);
	}

	x +=12;
	this->display->fillRect(4,x,8,8,BLACK);
	this->display->setCursor(18,x);
	this->display->drawRect(4,x,8,8,WHITE);
	this->display->print("denoice");
	if(activePoint == 2){
		this->display->fillRect(4,x,8,8,WHITE);
	}

	x +=12;
	this->display->fillRect(4,x,8,8,BLACK);
	this->display->setCursor(18,x);
	this->display->drawRect(4,x,8,8,WHITE);
	this->display->print("reset");
	if(activePoint == 3){
		this->display->fillRect(4,x,8,8,WHITE);
	}
	
	if(scann){
		measurement[i] = sc->scanIdx(i);
		float level = (float) measurement[i] / (float)sc->getMax();
		level *= 32;
		
		this->display->drawFastVLine((i+1)+76,8,40,BLACK);
		this->display->drawPixel((i)+76,48-level,WHITE);
		
		this->display->display();
		i++;
		if(i==40){
			scann = false;
			tracker->setMeasurements(measurement);
		}
	}else{
		i=0;
	}

	byte* dr = tracker->getDroneFreqs();

	for(int j = 0; j<tracker->getNumberOfDrones();j++){
		if((j!=lineidx) || !edit){
			this->display->drawFastVLine(dr[j]+76,16,30,WHITE);
		}else{
			int towait = 1000;
			if(editline){
				towait = 200;
			}
			if(time + towait < millis()){
				time = millis();
				drawline = !drawline;
				this->display->drawFastVLine(dr[j]+76,16,30,BLACK);
				if(drawline){
					this->display->drawFastVLine(dr[j]+76,16,30,WHITE);
				}else{
					float level = (float) measurement[dr[j]] / (float)sc->getMax();
					level *= 32;
					this->display->drawPixel((dr[j])+76,48-level,WHITE);
				}
			}
		}
	}

	this->display->drawFastVLine(0+76,12,40,WHITE);
	this->display->drawFastVLine(39+76,12,40,WHITE);


	/**/
}

void ScanForDrones::buttonNext(){
	switch (activePoint){
	case 0:
		scann = true;
		break;
	
	case 1:
		if(tracker->getNumberOfDrones() >0){
			edit = true;
			activePoint = 4;
			time = millis();
		}

		/* code */
		break;
	case 2:
		display->clearDisplay();
		display->setCursor(0,0);
		display->print("capture Noise");
		display->display();
		sc->captureNoise();
		tracker->setMaxOffset(sc->getMax());
		break;
	case 3:
		this->display->clearDisplay();
		tracker->reset();
		break;
	case 4:
		editline = !editline;
		break;
	}
}

void ScanForDrones::buttonUp(){
	if(!edit){
		if(this->activePoint ==0){
			this->activePoint= MENUENTRIES-1;
		}else{
			this->activePoint--;
		}
	}else{
		if(editline){
			byte* dr = tracker->getDroneFreqs();
			float level = (float) measurement[dr[lineidx]] / (float)sc->getMax();
			level *= 32;
			this->display->drawFastVLine(dr[lineidx]+76,16,30,BLACK);
			this->display->drawPixel((dr[lineidx])+76,48-level,WHITE);
			if(dr[lineidx] == 0){
				dr[lineidx] = 39;
			}else{
				dr[lineidx]--;
			}
		}else{
			if(this->lineidx == 0){
				this->lineidx= tracker->getNumberOfDrones()-1;
			}else{
				this->lineidx--;
			}
		}
		time = millis();
	}
}

void ScanForDrones::buttonDown(){
	if(!edit){
		this->activePoint++;
		this->activePoint %=MENUENTRIES;
	}else{
		if(editline){
			byte* dr = tracker->getDroneFreqs();
			float level = (float) measurement[dr[lineidx]] / (float)sc->getMax();
			level *= 32;
			this->display->drawFastVLine(dr[lineidx]+76,16,30,BLACK);
			this->display->drawPixel((dr[lineidx])+76,48-level,WHITE);
			dr[lineidx]++;
			dr[lineidx] %=40;
		}else{
			this->lineidx++;
			this->lineidx %=  tracker->getNumberOfDrones();
		}
		time = millis();
	}
}

void ScanForDrones::buttonPrev(){
	if(edit){
		if(editline){
			editline = false;
		}else{
		edit = false;
		activePoint = 1;
		drawline = true;
		}
	}else{
		this->parent->acitvateMe();
	}
}