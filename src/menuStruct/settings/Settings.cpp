#include "Settings.h"

Settings::Settings() : Menu("Main"){
	this->addEntry(MenuEntry{"DHT",0,0});
	this->addEntry(MenuEntry{"GPS",0,1});
	this->addEntry(MenuEntry{"..",0,2});
}

//actions before and after
void Settings::preActions(){

}

void Settings::postActions(){

}

void Settings::buttonAction(byte id){
	switch (id)
	{
		case 0:
			menuController->setActiveWindow(new DHTSettings());
			break;
		case 1:
			menuController->setActiveWindow(new GPSSettings());
			break;
		case 2:
			/* code */
			break;
		
		default:
			break;
	}
}