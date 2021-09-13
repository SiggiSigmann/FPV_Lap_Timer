#include <Arduino.h>

#include <Wire.h>
#include <SPI.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "RX5808/SPI_RX5808.h"
#include "RX5808/channels.h"

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

SPI_RX5808* rx;

void setup(){
  Serial.begin(9600);
  while (!Serial){}
  Serial.println("setup");

  //display
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.display();
 
  //Rx
  rx = new SPI_RX5808(A0);
}

void loop() {
  for(int i = 1; i<channelAmount*3;i+=3){

    //get frequenzy out of array, sorted by value
    rx->setFreq(pgm_read_word_near(channelFreqTable+pgm_read_word_near(channelList+i/3)));
    rx->waitTillValid();

    //get rssi level
    short level = rx->getRSSI()/10;

    //display level
    display.drawFastVLine(i+1+4,0,SCREEN_HEIGHT,BLACK);
    display.drawPixel(i+1+4,60-level,WHITE);
    display.display();
  }
}