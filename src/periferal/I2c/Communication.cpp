#include "Communication.h"

SerialCommunication::SerialCommunication(){
	Serial2.begin(9600);
}

String SerialCommunication::getString(String mes){
	Serial2.println(mes);
	while(!Serial2.available()){}
	if(Serial2.available()){
		String ret = Serial2.readStringUntil('\n');
		if(ret.equals(mes)) return "";
		return ret;
	}
	return "";
}

int SerialCommunication::getInt(String mes){
	Serial2.println(mes);
	while(!Serial2.available()){}
	if(Serial2.available()){
		String str = Serial2.readStringUntil('\n');
		if(str.equals(mes)) return 0;
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
		//Serial.println("pos"+str);
		if(str.equals(mes)) return res;
		byte semicolinIdx = str.indexOf(';');
		//.println(semicolinIdx);
		float f1 = str.substring(0,semicolinIdx-1).toFloat();
		float f2 = str.substring(semicolinIdx+1,str.length()).toFloat();
		//Serial.println(String(f1) + " " +String(f2) + "\n");
		this->res[0] = f1;
		this->res[1] = f2;
	}
	return this->res;
}

byte SerialCommunication::getByte(String mes){
	//Serial.println(mes);
	byte b=0;
	Serial2.println(mes);
	while(!Serial2.available()){}
	if(Serial2.available()){
		String str = Serial2.readStringUntil('\n');
		//Serial.println("sat:" +str);
		if(str.equals(mes)) return 0;
		b = (byte) str.toInt();
	}
	return b;
}

void  SerialCommunication::flush(){
	//Serial.println("error");
	Serial2.flush();
	while(Serial2.available() > 0) {
		Serial2.read();
	}
}