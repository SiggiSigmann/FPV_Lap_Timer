#include <Arduino.h>

#include <Wire.h>
#include <SPI.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "RX5808/SPI_RX5808.h"
#include "fpv/Scanner.h"

#include "menu/MainMenu.h"
#include "menu/Windows/Osciloskope.h"
#include "menu/Windows/RSSIMeter.h"
#include "menu/Windows/Selection.h"

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

SPI_RX5808* rx;
MainMenu* mm;
FPVScanner* scanner;


void setup() {


  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { 
    //Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.display();

  pinMode(15,INPUT);
  pinMode(16,INPUT);
  //pinMode(2,INPUT);
  pinMode( 3,INPUT);

  rx = new SPI_RX5808(A0);
  scanner = new FPVScanner(rx);

  //main Menu
  mm = new MainMenu(&display);

  //selection
  Selection* sel = new Selection(&display, mm, scanner);
  mm->setMainScreen(sel);
}

void loop() {
  mm->run();
}