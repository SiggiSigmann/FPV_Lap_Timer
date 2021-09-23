#include "ChannelScanner.h"


ChannelScanner::ChannelScanner(Adafruit_SSD1306* d, Menu* parent, Scanner* s):MenuPoint(d,parent){
	scan = s;
}

void ChannelScanner::draw(){
	//top
	this->display->setCursor(0,0);
	this->display->print("CHANNEL - SCOPE");

	//surounding
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

	//drawPoint of scann
	byte level = scaleRSSI(scan->scanIdx(i), 32, scan->getMax());

	Serial.println("ok");

	//thickness of 3
	for(byte j=0; j<3;j++){
		byte x = (i*3)+5+j;
		this->display->drawFastVLine(x,8,40,BLACK);
		this->display->drawPixel(x,48-level,WHITE);
	}
	//clear next dot because this will be updated
	this->display->drawFastVLine(((i+1)*3)+5,8,40,BLACK);

	//increment counter
	i++;
	i %=40;

	//print if denoised
	if(scan->isDenoise()){
		this->display->setCursor(50,55);
		this->display->print("Denoised");
	}
}

void ChannelScanner::buttonNext(){
	//denoise
	display->clearDisplay();
	display->setCursor(0,0);
	display->print("capture Noise");
	display->display();

	scan->captureNoise();

	display->clearDisplay();
}

void ChannelScanner::buttonUp(){
}
void ChannelScanner::buttonDown(){
}

void ChannelScanner::buttonPrev(){
	this->parent->acitvateMe();
	
	//reset counter
	i=0;
}
