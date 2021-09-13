#include "Osciloskope.h"


Osciloskope::Osciloskope(Adafruit_SSD1306* d, Menu* parent, FPVScanner* s):MenuPoint(d){
	Serial.println("huaa");
	scan = s;
	actvescann=true;
}

void Osciloskope::draw(){
	drawBottomline();

	this->display->display();
	osci();
}

void  Osciloskope::drawBottomline(){
	this->display->drawLine(4,48,124,48,WHITE);
	this->display->setCursor(4,55);
	this->display->print("5645");
	this->display->setCursor(102,55);
	this->display->print("5945");
	this->display->drawFastVLine(3,16,32,WHITE);
	this->display->drawFastHLine(1,16,4,WHITE);
	this->display->drawFastHLine(1,48,4,WHITE);
	for(int i = 0; i<=120;i+=10){
		this->display->drawPixel(4+i,49,WHITE);
		this->display->drawPixel(4+i,50,WHITE);
	}
}

void Osciloskope::osci(){
	while(actvescann){
		for(int i = 0; i<channelAmount;i++){
			float level = (float) scan->scanIdx(i) / (float)scan->getMax();
			level *= 32;
			for(int j=0; j<3;j++){
				this->display->drawFastVLine((i*3)+5+j,8,40,BLACK);
				this->display->drawPixel((i*3)+j+5,48-level,WHITE);
			}
			this->display->drawFastVLine(((i+1)*3)+5,8,40,BLACK);
			this->display->display();
		}
		processButton();
	}
}

void Osciloskope::processButton(){
	if(digitalRead(3)){
		actvescann = !actvescann;
	}
	if(digitalRead(4)){
		this->display->clearDisplay();
		this->display->display();
		scan->captureNoise();
		drawBottomline();
	}
}


