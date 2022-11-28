#include "MenuController.h"

MenuController::MenuController(Window* startWindow){
	pinMode(NEXTBUTTON, OUTPUT);
	pinMode(DOWNBUTTON, OUTPUT);
	pinMode(UPBUTTON, OUTPUT);
	pinMode(PREVBUTTON, OUTPUT);

	this->sc = new StackController();

	this->sc->push(startWindow);
	this->activeWindow = startWindow;

	pinMode(LED,OUTPUT);
}

void MenuController::run(){
	this->processButton();
	this->draw();

	toneManager->stop();
}

void MenuController::draw(){
	short timeSinceLastUpdate = millis()-lastUpdateTime;
	lastUpdateTime = millis();

	display.fillRect(0,0,128,16,BLACK);
	display.setCursor(0,0);
	display.print(activeWindow->getHeadline());
	display.print(":");
	display.print(activeWindow->getExtraInfromation());
	display.print("|");
	display.print(String(timeSinceLastUpdate));
	display.print("|");
	display.print(String(this->sc->getSize()));

	this->activeWindow->draw();

	toastManager->drawToast();
	display.display();	
}

void MenuController::buttonPrev(){
	this->activeWindow->buttonPrev();
}

void MenuController::buttonNext(){
	this->activeWindow->buttonNext();
}
void MenuController::buttonUp(){
	this->activeWindow->buttonUp();
}
void MenuController::buttonDown(){
	this->activeWindow->buttonDown();
}

void MenuController::processButton(){
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

void MenuController::setActiveWindow(Window* newWindow){
	newWindow->preActions();
	display.clearDisplay();
 	this->sc->push(this->activeWindow);
	this->activeWindow = newWindow;
}

void MenuController::windowBack(){
	Window* lastWindow = this->sc->pop();
	if(lastWindow == NULL) return;
	this->activeWindow->postActions();
	display.clearDisplay();
	this->activeWindow = lastWindow;
}

void MenuController::oneWindowBack(){
	if(this->sc->getSize()>1){
		display.clearDisplay();
		this->activeWindow->postActions();
		Window* old = this->sc->pop();
		this->activeWindow = old;
	}
}