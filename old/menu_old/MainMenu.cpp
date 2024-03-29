#include "MainMenu.h"

MainMenu::MainMenu():GUI(""){
	pinMode(NEXTBUTTON,OUTPUT);
	pinMode(PREVBUTTON,OUTPUT);
	pinMode(DOWNBUTTON,OUTPUT);
	pinMode(UPBUTTON,OUTPUT);
	pinMode(BEEPER,OUTPUT);
}

//draw display of active MenuPoint
void MainMenu::draw(){
	//noInterrupts()

	//stop beeper
	digitalWrite(BEEPER,0);

	byte fps = millis()-last;
	last = millis();

	display.fillRect(0,0,128,16,BLACK);
	display.setCursor(0,0);
	display.print(active->getHeadline());
	display.print(":");
	display.print(active->getExtraInfromation());
	display.print("|");
	display.print(String(fps));

	this->active->draw();

	toast->drawToast();
	display.display();

	//interrupts()
}

void MainMenu::setMainScreen(GUI* m){
	active = m;
}

//call methods of active MenuPoint
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
void MainMenu::acitvate(GUI* activateion){
	this->active->postActions();
	this->active = activateion;
	this->active->preActions();
}
void MainMenu::acitvateMe(){
	this->active->acitvateMe();
}

//draw display and precoess Buttons
void MainMenu::run(){
	this->draw();
	this->processButton();
}

//processs Buttons
void MainMenu::processButton(){
	if(digitalRead(NEXTBUTTON)){
		if(!next){
			pressedNext = millis();
			this->buttonNext();
			next = true;
		}else{
			if(longnext){
				if(FREQUENZE<millis()-pressedNext){
					pressedNext = millis();
					this->buttonNext();
				}
			}else{
				if(LONGEPRESS<millis()-pressedNext){
					pressedNext = millis();
					longnext=true;
					this->buttonNext();
				}
			}
		}
	}else{
		next = false;
		longnext=false;
	}

	if(digitalRead(PREVBUTTON)){
		if(!prev){
			pressedPrev = millis();
			this->buttonPrev();
			prev = true;
		}else{
			if(longprev){
				if(FREQUENZE<millis()-pressedPrev){
					pressedPrev = millis();
					this->buttonPrev();
				}
			}else{
				if(LONGEPRESS<millis()-pressedPrev){
					pressedPrev = millis();
					longprev=true;
					this->buttonPrev();
				}
			}
		}
	}else{
		prev = false;
		longprev=false;
	}

	if(digitalRead(DOWNBUTTON)){
		if(!down){
			pressedDown = millis();
			this->buttonDown();
			down = true;
		}else{
			if(longdown){
				if(FREQUENZE<millis()-pressedDown){
					pressedDown = millis();
					this->buttonDown();
				}
			}else{
				if(LONGEPRESS<millis()-pressedDown){
					pressedDown = millis();
					longdown=true;
					this->buttonDown();
				}
			}
		}
	}else{
		down = false;
		longdown = false;
	}

	if(digitalRead(UPBUTTON)){
		if(!up){
			pressedUp = millis();
			this->buttonUp();
			up = true;
		}else{
			if(longup){
				if(FREQUENZE<millis()-pressedUp){
					pressedUp = millis();
					this->buttonUp();
				}
			}else{
				if(LONGEPRESS<millis()-pressedUp){
					pressedUp = millis();
					longup=true;
					this->buttonUp();
				}
			}
		}
	}else{
		up = false;
		longup = false;
	}
}