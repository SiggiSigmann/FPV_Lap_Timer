#include "GPSSettings.h"


GPSSettings::GPSSettings(GUI* m):Menu("GPS SETTINGS",m){
}

void GPSSettings::drawMenu(){
	gps->update();

	Serial.println("huaaaa");
	drawPoint("MinSat: " + String(gps->getMinSat()));
	drawInfo("IsValid: " + String(gps->isValid()));
	drawInfo("Sats: " + String(gps->getSatelites()));

	Serial.println("1");
	float pos[2] = {0};
	gps->getPosition(pos);
	Serial.println("2");
	drawInfo("LAT: " +  String(pos[0],10));
	Serial.println("3");
	drawInfo("LNG: " +  String(pos[1],10));

	Serial.println("4");
	drawPoint("SummerTime: " + String(gps->getSommerTime()));
	drawPoint("TimeZone: "+String( gps->getTimeSzone()));

	Serial.println("huaaaa");
	String date = gps->getDate();
	drawInfo(gps->getTime() +" "+date.substring(0,6)+date.substring(8,10));
	
}

void GPSSettings::buttonNext(){
	switch (activeEntry){
		case 0:
			editinSat=true;
			break;
			
		case 5:
			editSommerTime=true;
			break;
		
		
		case 6:
			editTimeSzone=true;
			break;
	}
}

void GPSSettings::buttonUp(){
	Serial.println(String(editinSat));
	if(editSommerTime){
		gps->setSommerTime(!gps->getSommerTime());
	}else if(editTimeSzone){
		int times = gps->getTimeSzone()-1;
		if(times <= -12){
			times = 12;
		}
		gps->setTimeSzone(times);
	}else if(editinSat){
		Serial.println("up");
		int times = gps->getMinSat()-1;
		if(times <= 0){
			times= (15);
		}
		
		gps->setMinSat(times);
	}else{
		Menu::buttonUp();
	}
}

void GPSSettings::buttonDown(){
	if(editSommerTime){
		gps->setSommerTime(!gps->getSommerTime());
	}else if(editTimeSzone){
		int times = gps->getTimeSzone()+1;
		if(times >= 13){
			times= (-11);
		}
		
		gps->setTimeSzone(times);
	}else if(editinSat){
		int times = gps->getMinSat()+1;
		if(times >= 15){
			times= (1);
		}
		
		gps->setMinSat(times);
	}else{
		Menu::buttonDown();
	}
}

void GPSSettings::buttonPrev(){
	if(editSommerTime){
		editSommerTime = false;
	}else if(editTimeSzone){
		editTimeSzone = false;
	}else if(editinSat){
		editinSat = false;
	}else{
		Menu::buttonPrev();
	}
}

