#include "tonegenerator.h"

void onTimer(){
	toneGenerator->tickSound();
}

void Tone::playDrone(byte i){
	Serial.println((i+1)*440);
	play((i+1)*440);
}

Tone::Tone(){
	timer = timerBegin(0, 80, true);
	timerAttachInterrupt(timer, &onTimer, true);
}

void Tone::play(int freq){
	timeToPlay = millis();
	timerAlarmWrite(timer, 1000000/freq, true);
	timerAlarmEnable(timer);
}

void Tone::stop(){
	if((millis()-timeToPlay)>1000){
		timerAlarmDisable(timer);
		digitalWrite(25,false);
	}
}

void Tone::tickSound(){
	soundFlag= !soundFlag;
	digitalWrite(25,soundFlag);
}


