#include "MainMenu.h"

MainMenu::MainMenu() : Menu("Main"){
	this->addEntry(MenuEntry{"Measurings",0,0});
	this->addEntry(MenuEntry{"Laptracker",0,1});
	this->addEntry(MenuEntry{"Settings",0,2});
}

//actions before and after
void MainMenu::preActions(){

}

void MainMenu::postActions(){

}

void MainMenu::buttonAction(byte id){
	switch (id)
	{
		case 0:
			/* code */
			break;
		case 1:
			/* code */
			break;
		case 2:
			menuController->setActiveWindow(new Settings());
			break;
		
		default:
			break;
	}
}