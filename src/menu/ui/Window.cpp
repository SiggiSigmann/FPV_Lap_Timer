#include "Window.h"

Window::Window(String name){
	this->headline = name;
	this->headline.toUpperCase();
}

String Window::getHeadline(){
	return headline;
}

String Window::getExtraInfromation(){
	return extraInformation;
}

void Window::setExtraInfromation(String extra){
	this->extraInformation = extra;
}

void Window::preActions(){};
void Window::postActions(){};

void Window::buttonPrev(){
	menuController->oneWindowBack();
}