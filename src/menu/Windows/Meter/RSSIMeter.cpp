#include "RSSIMeter.h"


RSSIMeter::RSSIMeter(Window* parent):MenuWindow("RSSI - SCOPE",parent){
}

void RSSIMeter::draw(){
	//drawchannelname
	display.fillRect(4,55,70,8,BLACK);
	display.setCursor(4,55);
	display.print("Channel:");
	display.print( pgm_read_word_near(channelNames+channel),HEX);

	//surounding
	display.drawLine(4,48,124,48,WHITE);
	display.drawFastVLine(3,16,32,WHITE);
	display.drawFastHLine(1,16,4,WHITE);
	display.drawFastHLine(1,48,4,WHITE);
	for(int i = 0; i<=120;i+=10){
		display.drawPixel(4+i,49,WHITE);
		display.drawPixel(4+i,50,WHITE);
	}

	//draw values
	byte level = scaleRSSI(scanner->scanIdx(channel), 32, scanner->getMax());

	//insert into array
	insertAtEnd(old, level ,LASTVALUES);

	//print
	for(int i = LASTVALUES-1; i>=0; i--){
		display.drawFastVLine(i+5,8,40,BLACK);
		display.drawPixel(i+5,48-old[i],WHITE);
	}
	
	//wait because ESP ist too fast
	delay(DELAVFORRSSI);

	if(scanner->isDenoise()){
		display.setCursor(70,55);
		display.print("Denoised");
	}

}

void RSSIMeter::buttonNext(){
	//denoise
	display.clearDisplay();
	display.setCursor(0,0);
	display.print("capture Noise");
	display.display();

	scanner->captureNoise();

	display.clearDisplay();
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


