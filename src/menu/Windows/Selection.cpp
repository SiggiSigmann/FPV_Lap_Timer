#include "Selection.h"

Selection::Selection(Adafruit_SSD1306* d, AbstractMenu* m, Scanner* sc):SubMenuList("MENU", d, m, 3){
	meter = new Measuring(d, this, sc);
	lap = new LapMenu(d, this, sc);
	settings = new Settings(d, this, sc);
}

void Selection::draw(){
	byte idx = 0;
	drawPoint(idx++, "Measurings");
	drawPoint(idx++, "Laptracker");
	drawPoint(idx++, "Settings");

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
			settings->acitvateMe();
			break;
	}
}