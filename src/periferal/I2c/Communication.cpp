#include "Communication.h"

SerialCommunication::SerialCommunication(){
	Serial2.begin(9600);
}

String SerialCommunication::getString(String mes){
	Serial2.println(mes);
	while(!Serial2.available()){}
	if(Serial2.available()){
		return Serial2.readStringUntil('\n');
	}
	return "";
}

int SerialCommunication::getInt(String mes){
	Serial2.println(mes);
	while(!Serial2.available()){}
	if(Serial2.available()){
		String str = Serial2.readStringUntil('\n');
		return str.toInt();
	}
	return 0;
}

float* SerialCommunication::getFloatArray2(String mes){
	this->res[2] = {-1};
	Serial2.println(mes);
	while(!Serial2.available()){}
	if(Serial2.available()){
		String str = Serial2.readStringUntil('\n');
		byte semicolinIdx = str.indexOf(';');
		float f1 = str.substring(0,semicolinIdx-1).toFloat();
		float f2 = str.substring(semicolinIdx+1,str.length()).toFloat();
		this->res[0] = f1;
		this->res[1] = f2;
	}
	return this->res;
}

byte SerialCommunication::getByte(String mes){
	byte b=0;
	Serial2.println(mes);
	while(!Serial2.available()){}
	if(Serial2.available()){
		b = (byte) Serial2.readStringUntil('\n').toInt();
	}
	return b;
}