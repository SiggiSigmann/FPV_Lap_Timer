#include "Selection.h"

Selection::Selection(AbstractMenu* m, Scanner* sc):SubMenuList("MENU", m, 3){
	meter = new Measuring(this, sc);
	lap = new LapMenu(this, sc);
	settings = new Settings(this, sc);
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