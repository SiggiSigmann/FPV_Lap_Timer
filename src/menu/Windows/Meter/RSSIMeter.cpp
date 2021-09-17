#include "RSSIMeter.h"


RSSIMeter::RSSIMeter(Adafruit_SSD1306* d, Menu* parent, FPVScanner* s):MenuPoint(d,parent){
	//Serial.println("huaa");
	scan = s;
	actvescann=true;
}

void RSSIMeter::draw(){
	drawBottomline();

	this->display->display();
	osci();
}

void  RSSIMeter::drawBottomline(){
	this->display->setCursor(0,0);
	this->display->print("RSSI - Scope");
	this->display->fillRect(4,55,70,8,BLACK);
	this->display->setCursor(4,55);
	this->display->print("Channel:");
	this->display->print( pgm_read_word_near(channelNames+channel),HEX);

	this->display->drawLine(4,48,124,48,WHITE);
	//this->display->setCursor(4,55);
	//this->display->print("5645");
	//this->display->setCursor(102,55);
	//this->display->print("5945");
	this->display->drawFastVLine(3,16,32,WHITE);
	this->display->drawFastHLine(1,16,4,WHITE);
	this->display->drawFastHLine(1,48,4,WHITE);
	for(int i = 0; i<=120;i+=10){
		this->display->drawPixel(4+i,49,WHITE);
		this->display->drawPixel(4+i,50,WHITE);
	}

	if(scan->isDenoiced()){
		this->display->setCursor(70,55);
		this->display->print("No Noice");
	}
}

void RSSIMeter::osci(){

	//while(actvescann){
		float level = (float) scan->scanIdx(channel) / (float)scan->getMax();
		level *= 32;
		int o = level;
		for(int i = 119; i>=0;i--){
			int ol = old[i];
			old[i] = o;
			o = ol;

			this->display->drawFastVLine(i+5,8,40,BLACK);
			this->display->drawPixel(i+5,48-old[i],WHITE);
			
		}
		

		delay(100);


	//}
}


void RSSIMeter::buttonNext(){
	display->clearDisplay();
	display->setCursor(0,0);
	display->print("capture Noise");
	display->display();
	scan->captureNoise();
	display->clearDisplay();
	drawBottomline();
}
void RSSIMeter::buttonUp(){
	channel--;
	if(channel < 0){
		channel = 39;
	}
}
void RSSIMeter::buttonDown(){
	channel++;
	channel %= 40;
}


