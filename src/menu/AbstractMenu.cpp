#include "AbstractMenu.h"

AbstractMenu::AbstractMenu(Adafruit_SSD1306* d){
	display = d;
}

Adafruit_SSD1306* AbstractMenu::getDisplay(){
	return display;
}