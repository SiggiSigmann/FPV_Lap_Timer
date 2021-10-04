#include "RSSIMeter.h"


RSSIMeter::RSSIMeter(Adafruit_SSD1306* d, AbstractMenu* parent, Scanner* s):MenuWindow(d,parent){
	scan = s;
}

void RSSIMeter::draw(){
	//top
	this->display->setCursor(0,0);
	this->display->print("RSSI - SCOPE:");

	//drawchannelname
	this->display->fillRect(4,55,70,8,BLACK);
	this->display->setCursor(4,55);
	this->display->print("Channel:");
	this->display->print( pgm_read_word_near(channelNames+channel),HEX);

	//surounding
	this->display->drawLine(4,48,124,48,WHITE);
	this->display->drawFastVLine(3,16,32,WHITE);
	this->display->drawFastHLine(1,16,4,WHITE);
	this->display->drawFastHLine(1,48,4,WHITE);
	for(int i = 0; i<=120;i+=10){
		this->display->drawPixel(4+i,49,WHITE);
		this->display->drawPixel(4+i,50,WHITE);
	}

	//draw values
	byte level = scaleRSSI(scan->scanIdx(channel), 32, scan->getMax());

	//insert into array
	insertAtEnd(old, level ,LASTVALUES);

	//print
	for(int i = LASTVALUES-1; i>=0; i--){
		this->display->drawFastVLine(i+5,8,40,BLACK);
		this->display->drawPixel(i+5,48-old[i],WHITE);
	}
	
	//wait because ESP ist too fast
	delay(DELAVFORRSSI);

	if(scan->isDenoise()){
		this->display->setCursor(70,55);
		this->display->print("Denoised");
	}

}

void RSSIMeter::buttonNext(){
	//denoise
	display->clearDisplay();
	display->setCursor(0,0);
	display->print("capture Noise");
	display->display();

	scan->captureNoise();

	display->clearDisplay();
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


