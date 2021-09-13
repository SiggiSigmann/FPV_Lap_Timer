#include "MainMenu.h"

MainMenu::MainMenu(Adafruit_SSD1306* d):Menu(d){
	Serial.println("kmd");
}

void MainMenu::draw(){
	this->active->draw();
}
void MainMenu::processButton(){
	this->active->processButton();
}

void MainMenu::setMainScreen(Menu* m){
	active = m;
}

void MainMenu::acitvate(Menu* activateion){
	this->active = activateion;
}

void MainMenu::acitvateMe(){
	this->active->acitvateMe();
}

void MainMenu::run(){
	this->draw();
	this->processButton();
}