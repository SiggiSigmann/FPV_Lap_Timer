#include "Selection.h"

Selection::Selection(Adafruit_SSD1306* d, Menu* m, Scanner* sc):MenuList(d, m, 3){
	meter = new Measuring(d, this, sc);
	lap = new LapMenu(d, this, sc);
	scanSettings = new ScanSettings(d, this, sc);
}

void Selection::draw(){
	//top
	this->display->setCursor(0,0);
	this->display->print("MENU:");

	//menu
	byte idx = 0;
	drawPoint(idx++, "Measurings");
	drawPoint(idx++, "LAPTRACKER");
	drawPoint(idx++, "Scanner Settings");

}	

void Selection::buttonNext(){
	switch (activePoint){
		case 0:
			meter->acitvateMe();
			break;
			
		case 1:
			lap->acitvateMe();
			break;

		case 2:
			scanSettings->acitvateMe();
			break;
	}
}