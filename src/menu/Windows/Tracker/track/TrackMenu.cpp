#include "TrackMenu.h"

TrackMenu::TrackMenu(AbstractMenu* m):SubMenuList("TRACK - MENU",m){
}

void TrackMenu::drawMenu(){
	drawPoint("Record Track");
	drawPoint("View Track");
	drawPoint("Select: " + String(trackManager->getSelected()));
}	

void TrackMenu::buttonNext(){
	switch (activePoint){
		case 0:

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
		SubMenuList::buttonUp();

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
		SubMenuList::buttonDown();

	}
}

void TrackMenu::buttonPrev(){
	if(editNumber){
		editNumber = false;
	}else{
		SubMenuList::buttonPrev();
	}
}

