#include "mySPI.h"


void MySPI::begin(){
    //define pinmode
	pinMode(DATA, OUTPUT);
	pinMode(CLOCK, OUTPUT);
}

//transphere byte
void MySPI::transfer(byte byte){
	for (uint8_t i = 0; i < 8; i++) {
        sendBit(byte & 0x1);
        byte >>= 1;
    }
}

//send a bit with clock
void inline MySPI::sendBit(boolean bit){
	digitalWrite(CLOCK, LOW);
    delayMicroseconds(1);

    digitalWrite(DATA, bit);
    delayMicroseconds(1);
    
    digitalWrite(CLOCK, HIGH);
    delayMicroseconds(1);

    digitalWrite(CLOCK, LOW);
    delayMicroseconds(1);
}