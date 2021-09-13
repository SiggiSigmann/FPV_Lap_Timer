#include <Arduino.h>

#include <Wire.h>
#include <SPI.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "RX5808/SPI_RX5808.h"
#include "RX5808/channels.h"

#include "menu/MainMenu.h"
#include "menu/Windows/Osciloskope.h"
#include "free.h"

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

SPI_RX5808* rx;

MainMenu* mm;


void setup(){
  Serial.begin(9600);
  while (!Serial){}
  Serial.println("setup");
  Serial.println(freeMemory());

  //display
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.display();


  mm = new MainMenu(&display);

  Serial.println(freeMemory());
  
  Osciloskope* o = new Osciloskope(&display, mm);
  mm->setMainScreen(o);
  Serial.println(freeMemory());

  //Rx
  rx = new SPI_RX5808(A0);

  Serial.println("end setup");
}

void loop() {
  mm->run();
}