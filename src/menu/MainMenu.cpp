#include "MainMenu.h"

MainMenu::MainMenu(Adafruit_SSD1306* d):Menu(d){
	pinMode(NEXTBUTTON,OUTPUT);
	pinMode(PREVBUTTON,OUTPUT);
	pinMode(DOWNBUTTON,OUTPUT);
	pinMode(UPBUTTON,OUTPUT);
}

void MainMenu::draw(){
	this->active->draw();
	this->display->display();
}

void MainMenu::buttonPrev(){
	this->active->buttonPrev();
}
void MainMenu::buttonNext(){
	this->active->buttonNext();
}
void MainMenu::buttonUp(){
	this->active->buttonUp();
}
void MainMenu::buttonDown(){
	this->active->buttonDown();
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

void MainMenu::processButton(){
	if(digitalRead(NEXTBUTTON)){
		if(!next){
			this->buttonNext();
			next = true;
		}
	}else{
		next = false;
	}

	if(digitalRead(PREVBUTTON)){
		if(!prev){
			this->buttonPrev();
			prev = true;
		}
	}else{
		prev = false;
	}

	if(digitalRead(DOWNBUTTON)){
		if(!down){
			this->buttonDown();
			down = true;
		}
	}else{
		down = false;
	}

	if(digitalRead(UPBUTTON)){
		if(!up){
			this->buttonUp();
			up = true;
		}
	}else{
		up = false;
	}
}