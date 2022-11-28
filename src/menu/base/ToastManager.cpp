#include "ToastManager.h"

ToastManager::ToastManager(){
	pinMode(LED, OUTPUT);

	queue = new LinkedList<Toast*>();
}

ToastManager::~ToastManager(){
	//delete queue;
}

void ToastManager::addToast(Toast* newToast){
	queue->add(newToast);
}

bool ToastManager::drawToast(){
	bool needToDraw = needToDisplayToast();
	digitalWrite(LED,needToDraw);
	if(needToDraw){
		display.fillRoundRect(xSpace,0,length,12,4,WHITE);	

		display.setTextColor(BLACK);
		display.setCursor(xSpace+2,2);
		display.print(momentaryToast->message);
		display.setTextColor(WHITE);
		return true;
	}
	return false;
}

bool ToastManager::needToDisplayToast(){
	if(millis() <= endTimeForToast) return true;
	if(queue->size() > 0){
		getNextToast();
		return true;
	}
	return false;
}

void ToastManager::getNextToast(){
	if(momentaryToast != NULL) delete momentaryToast;
	momentaryToast = queue->shift();

	int16_t x1, y1;
	uint16_t w, h;
	display.getTextBounds(momentaryToast->message, 0, 0, &x1, &y1, &w, &h);
	length = w+4;
	xSpace = (SCREEN_WIDTH-length)/2;

	endTimeForToast = millis()+momentaryToast->duration;
}
