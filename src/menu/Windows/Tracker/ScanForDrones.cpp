#include "ScanForDrones.h"

ScanForDrones::ScanForDrones(AbstractMenu* m):SubMenuList("SCAN FOR DRONES",m){

	this->setExtra("0");
}

void ScanForDrones::drawMenu(){
	drawPoint("Scan", 70);
	drawPoint("Edit",70);
	drawPoint("Add",70);
	drawPoint("Delete",70);
	drawPoint("Denoise",70);
	drawPoint("Reset",70);

	//graph
	display.drawLine(84,48,124,48,WHITE);
	display.setCursor(4,55);
	display.drawFastVLine(84,16,34,WHITE);
	display.drawFastVLine(124,16,34,WHITE);
	for(int i = 0; i<=40;i+=10){
		display.drawPixel(84+i,49,WHITE);
		display.drawPixel(84+i,50,WHITE);
	}

	//scann
	if(isScanning){
		byte level = scaleRSSI(scanner->scanIdx(i), 32,scanner->getMax());
		display.drawFastVLine((i+1)+84,8,40,BLACK);
		display.drawPixel((i)+84,48-level,WHITE);
		
		//push itterateor and stop if finised
		i++;
		if(i==40){
			isScanning = false;

			//execute detection
			droneDetector->setMeasurements(scanner->getLastScan());
			this->setExtra(String(droneDetector->getNumberOfDrones()));
		}
	}else{
		i=0;
	}

	//celar channelname
	display.fillRect(64,55,60,10,BLACK);

	//draw drones
	byte* drones = droneDetector->getDroneFreqs();
	for(int j = 0; j<droneDetector->getNumberOfDrones();j++){

		if((j!=lineidx) || (!edit && !deleteDrone)){
			//only display if nothing will be moved or edit
			display.drawFastVLine(drones[j]+84,18,30,WHITE);
		}else{
			//line blinks in different speed
			int towait = 500;
			if(editline){
				towait = 200;

			}

			if(j==lineidx){
				//draw Channelname
				display.setCursor(64,55);
				display.print(pgm_read_word_near(channelNames + pgm_read_word_near(channelList + drones[lineidx]) ),HEX);
			}

			if(time + towait < millis()){
				time = millis();
				drawline = !drawline;
				display.drawFastVLine(drones[j]+84,18,30,BLACK);
				if(drawline){
					//draw line
					display.drawFastVLine(drones[j]+84,18,30,WHITE);
				}else{
					//if no line 0> draw point
					byte level = scaleRSSI(scanner->getLastScan()[drones[j]], 32,scanner->getMax());
					display.drawPixel((drones[j])+84,48-level,WHITE);
				}
			}
		}
	}

	if(scanner->isDenoise()) droneDetector->setOffset(scanner->getMax()/2);
}

void ScanForDrones::buttonNext(){
	switch (activePoint){
		case 0:
			//scan for Drones
			droneDetector->reset();
			isScanning = true;
			break;
		
		case 1:
			//edit if there is someting
			if(droneDetector->getNumberOfDrones() >0){
				edit = true;
				activePoint = 6;
				time = millis();
			}
			break;

		case 2:
			droneDetector->addDrone();
			this->setExtra(String(droneDetector->getNumberOfDrones()));
			break;

		case 3:
			if(deleteDrone){
				byte* drones = droneDetector->getDroneFreqs();
				display.drawFastVLine(drones[lineidx]+84,18,30,BLACK);
				byte level = scaleRSSI(scanner->getLastScan()[drones[lineidx]], 32,scanner->getMax());
				display.drawPixel((drones[lineidx])+84,48-level,WHITE);

				droneDetector->deleteDrone(lineidx);
				this->setExtra(String(droneDetector->getNumberOfDrones()));
				lineidx=0;
			}
			deleteDrone = true;
			break;

		case 4:
			//scan noise
			display.clearDisplay();
			display.setCursor(0,0);
			display.print("capture Noise");
			display.display();

			scanner->captureNoise();
			//detector->setOffset(scan->getMaxNoise());
			break;
		case 5:
			//reset
			display.clearDisplay();
			droneDetector->reset();
			this->setExtra(String(droneDetector->getNumberOfDrones()));
			break;
		case 6:
			// a trick => switch between edit
			editline = !editline;
			break;
	}
}

void ScanForDrones::buttonUp(){
	if(!edit && !deleteDrone){
		SubMenuList::buttonUp();
	}else{
		if(editline){
			//move line
			byte* drones = droneDetector->getDroneFreqs();
			byte level = scaleRSSI(scanner->getLastScan()[drones[lineidx]], 32,scanner->getMax());

			//remove old line
			display.drawFastVLine(drones[lineidx]+84,18,30,BLACK);
			display.drawPixel((drones[lineidx])+84,48-level,WHITE);

			//move
			if(drones[lineidx] == 0){
				drones[lineidx] = 39;
			}else{
				drones[lineidx]--;
			}

			
		}else{
			//choose line
			if(this->lineidx == 0){
				this->lineidx= droneDetector->getNumberOfDrones()-1;
			}else{
				this->lineidx--;
			}
		}

		//make line appear faster
		time = millis();
	}
}

void ScanForDrones::buttonDown(){
	if(!edit&&!deleteDrone){
		//nomral menu stuff
		SubMenuList::buttonDown();
	}else{
		if(editline){
			//move lines
			byte* drones = droneDetector->getDroneFreqs();
			byte level = scaleRSSI(scanner->getLastScan()[drones[lineidx]], 32,scanner->getMax());

			//remove old line
			display.drawFastVLine(drones[lineidx]+84,18,30,BLACK);
			display.drawPixel((drones[lineidx])+84,48-level,WHITE);

			drones[lineidx]++;
			drones[lineidx] %=40;
		}else{

			//select line
			this->lineidx++;
			this->lineidx %=  droneDetector->getNumberOfDrones();
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
	}else if(deleteDrone){
		deleteDrone = false;
	}else{
		SubMenuList::buttonPrev();
	}
}