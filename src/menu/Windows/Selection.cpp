#include "Selection.h"

Selection::Selection(GUI* m):Menu("MENU", m){
	meter = new Measuring(this);

	lap = new LapMenu(this);
	settings = new Settings(this);
}

void Selection::drawMenu(){
	drawPoint("Measurings");
	drawPoint("Laptracker");
	drawPoint("Settings");
}	

void Selection::buttonNext(){
	switch (activeEntry){
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