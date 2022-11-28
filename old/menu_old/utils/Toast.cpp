#include "Toast.h"

void Toast::setToast(String message){
	this->activeTill = millis()+1000;
	this->message = message;

	int16_t x1, y1;
	uint16_t w, h;
	display.getTextBounds(this->message, 0, 0, &x1, &y1, &w, &h);
	length = w+4;
	xSpace = (SCREEN_WIDTH-length)/2;

	
}

void Toast::drawToast(){
	
	if(this->activeTill>millis()){
		display.fillRoundRect(xSpace,0,length,12,4,WHITE);	

		display.setTextColor(BLACK);
		display.setCursor(xSpace+2,2);
		display.print(this->message);
		display.setTextColor(WHITE);
	}
}