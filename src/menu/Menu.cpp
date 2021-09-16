#include "Menu.h"

Menu::Menu(Adafruit_SSD1306* d){
	display = d;
}

Adafruit_SSD1306* Menu::getDisplay(){
	return display;
}