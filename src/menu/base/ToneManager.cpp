#include "ToneManager.h"

void onTimer(){
	toneManager->tickSound();
}

void ToneManager::playDrone(byte i){
	play((i+1)*440);
}

ToneManager::ToneManager(){
	pinMode(BEEPER,OUTPUT);
	timer = timerBegin(0, 80, true);
	timerAttachInterrupt(timer, &onTimer, true);
}

void ToneManager::play(int freq){
	timeToPlay = millis();
	timerAlarmWrite(timer, 1000000/freq, true);
	timerAlarmEnable(timer);
}

void ToneManager::stop(){
	if((millis()-timeToPlay)>1000){
		timerAlarmDisable(timer);
		digitalWrite(BEEPER,false);
	}
}

void ToneManager::tickSound(){
	soundFlag= !soundFlag;
	digitalWrite(BEEPER,soundFlag);
}


