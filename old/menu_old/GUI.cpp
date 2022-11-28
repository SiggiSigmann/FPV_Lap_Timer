#include "GUI.h"

GUI::GUI(String name){
	this->headline = name;
	this->headline.toUpperCase();
}

String GUI::getHeadline(){
	return headline;
}

String GUI::getExtraInfromation(){
	return extraInformation;
}

void GUI::setExtraInfromation(String extra){
	this->extraInformation = extra;
}

void GUI::preActions(){};
void GUI::postActions(){};