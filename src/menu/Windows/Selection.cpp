#include "Selection.h"

Selection::Selection(AbstractMenu* m, Scanner* sc):SubMenuList("MENU", m){
	meter = new Measuring(this, sc);
	lap = new LapMenu(this, sc);
	settings = new Settings(this, sc);
}

void Selection::drawMenu(){
	drawPoint("Measurings");
	drawPoint("Laptracker");
	drawPoint("Settings");
	drawPoint("1");
	drawPoint("2");
	drawPoint("3");
	drawPoint("4");
	drawPoint("5");
	drawPoint("6");
	drawPoint("7");

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