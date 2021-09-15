#include "Osciloskope.h"


Osciloskope::Osciloskope(Adafruit_SSD1306* d, Menu* parent, FPVScanner* s):MenuPoint(d,parent){
	scan = s;
	actvescann=true;
}

void Osciloskope::draw(){
	drawBottomline();

	this->display->display();
	osci();
}

void  Osciloskope::drawBottomline(){
	this->display->setCursor(0,0);
	this->display->print("Channel - Scope");
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

	if(scan->isDenoiced()){
		this->display->setCursor(50,55);
		this->display->print("No Noice");
	}
}

void Osciloskope::osci(){

	
		float level = (float) scan->scanIdx(i) / (float)scan->getMax();
		level *= 32;
		for(byte j=0; j<3;j++){
			this->display->drawFastVLine((i*3)+5+j,8,40,BLACK);
			this->display->drawPixel((i*3)+j+5,48-level,WHITE);
		}
		this->display->drawFastVLine(((i+1)*3)+5,8,40,BLACK);
		this->display->display();

	i++;
	i %=40;
	
}


void Osciloskope::buttonNext(){
	this->display->clearDisplay();
	this->display->display();
	scan->captureNoise();
	drawBottomline();
}
void Osciloskope::buttonUp(){

}
void Osciloskope::buttonDown(){

}
void Osciloskope::buttonPrev(){
	this->parent->acitvateMe();
	i=0;
}
