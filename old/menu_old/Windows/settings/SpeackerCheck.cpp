#include "SpeackerCheck.h"

SpeackerCheck::SpeackerCheck(GUI* m):Menu("Speacker Check",m){
}

void SpeackerCheck::drawMenu(){
	drawPoint("Play Sounds");
	for(byte i = 0; i<8;i++){
		drawPoint("Play Drone"+String(i));
	}

	if(playthough){
		if((millis()-playTime)>200){
			playTime = millis();
			toneGenerator->playDrone(soundIdx++);
			if(soundIdx>=8){
				soundIdx=0;
				playthough = false;
			}
		}
	}
}

void SpeackerCheck::buttonNext(){
	switch (activeEntry){
		case 0:
			playthough = true;
			playTime=millis();
			break;
		case 1:
			toneGenerator->playDrone(0);
			break;
		case 2:
			toneGenerator->playDrone(1);
			break;
		case 3:
			toneGenerator->playDrone(2);
			break;
		case 4:
			toneGenerator->playDrone(3);
			break;
		case 5:
			toneGenerator->playDrone(4);
			break;
		case 6:
			toneGenerator->playDrone(5);
			break;
		case 7:
			toneGenerator->playDrone(6);
			break;
		case 8:
			toneGenerator->playDrone(7);
			break;
	}
}

void SpeackerCheck::buttonPrev(){
	playthough = false;
	soundIdx=0;
	Menu::buttonPrev();
}