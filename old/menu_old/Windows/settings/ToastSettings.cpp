#include "ToastSettings.h"

ToastSettings::ToastSettings(GUI* m):Menu("Toast Settings",m){
}

void ToastSettings::drawMenu(){
	drawPoint("test");
	drawPoint("k");
	drawPoint("laaaaaaaang");
}

void ToastSettings::buttonNext(){
	switch (activeEntry){
		case 0:
			toast->setToast("test");
			break;
		case 1:
			toast->setToast("k");
			break;
		case 2:
			toast->setToast("laaaaaaaang");
			break;
	}
}
