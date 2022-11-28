#include "ChannelScanner.h"


ChannelScanner::ChannelScanner(GUI* parent):Frame("CHANNEL - SCOPE",parent){

}

void ChannelScanner::draw(){
	gps->update();				//update to avoid clitching

	//surounding
	display.drawLine(4,48,124,48,WHITE);
	display.setCursor(4,55);
	display.print("5645");
	display.setCursor(102,55);
	display.print("5945");
	display.drawFastVLine(3,16,32,WHITE);
	display.drawFastHLine(1,16,4,WHITE);
	display.drawFastHLine(1,48,4,WHITE);
	for(int i = 0; i<=120;i+=10){
		display.drawPixel(4+i,49,WHITE);
		display.drawPixel(4+i,50,WHITE);
	}

	//drawPoint of scann
	byte level = scaleRSSI(scanner->scanIdx(i), 32, scanner->getMax());

	//thickness of 3
	for(byte j=0; j<3;j++){
		byte x = (i*3)+5+j;
		display.drawFastVLine(x,8,40,BLACK);
		display.drawPixel(x,48-level,WHITE);
	}
	//clear next dot because this will be updated
	display.drawFastVLine(((i+1)*3)+5,8,40,BLACK);

	//increment counter
	i++;
	i %=40;

	//print if denoised
	if(scanner->isDenoise()){
		display.setCursor(50,55);
		display.print("Denoised");
	}
}

void ChannelScanner::buttonNext(){
	//denoise
	display.clearDisplay();
	display.setCursor(0,0);
	display.print("capture Noise");
	display.display();

	scanner->captureNoise();

	display.clearDisplay();
}

void ChannelScanner::buttonUp(){
}
void ChannelScanner::buttonDown(){
}

void ChannelScanner::buttonPrev(){
	Frame::buttonPrev();
	
	//reset counter
	i=0;
}
