#include "TrackMenu.h"

TrackMenu::TrackMenu(GUI* m):Menu("TRACK - MENU",m){
	//trackRecorter = new TrackRecorder(this);
}

void TrackMenu::drawMenu(){
	drawPoint("Record Track");
	drawPoint("View Track");
	drawPoint("Select: " + String(trackManager->getSelected()));
}	

void TrackMenu::buttonNext(){
	switch (activeEntry){
		case 0:
			//trackRecorter->acitvateMe();
			break;
		case 1:

			break;
		case 2:
			editNumber = true;
			break;
	}
}

void TrackMenu::buttonUp(){
	if(editNumber){
		byte number = trackManager->getSelected();
		if(number == 0 ){
			number = trackManager->getTrackNumber()-1;
		}else{
			number--;
		}
		trackManager->setselected(number);
	}else{
		Menu::buttonUp();

	}
}

void TrackMenu::buttonDown(){
	if(editNumber){
		byte number = trackManager->getSelected();
		number++;
		if(number>=trackManager->getTrackNumber()){
			number = 0;
		}
		trackManager->setselected(number);
	}else{
		Menu::buttonDown();

	}
}

void TrackMenu::buttonPrev(){
	if(editNumber){
		editNumber = false;
	}else{
		Menu::buttonPrev();
	}
}

