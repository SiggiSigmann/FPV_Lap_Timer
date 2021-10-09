#include <Arduino.h>

#include <Wire.h>
#include <SPI.h>

#include "RX5808/SPI_RX5808.h"
#include "fpv/Scanner.h"

#include "menu/MainMenu.h"
#include "menu/Windows/Selection.h"

#include "util/sdcard.h"
#include "util/gps.h"

#include "util/display.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

SPI_RX5808* rx;
MainMenu* mm;
Scanner* scanner;

void setup() {
	//no interupt while drawing to the display
	noInterrupts();

	Serial.begin(115200);
	while(!Serial){}

	pinMode(25,OUTPUT);

	if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { 
	Serial.println(F("SSD1306 allocation failed"));
		for(;;); // Don't proceed, loop forever
	}
	display.clearDisplay();
	display.setTextSize(0);
	display.setTextColor(WHITE);
	display.display();

	//setup receiver
	rx = new SPI_RX5808(34);
	scanner = new Scanner(rx);

	//main Menu
	mm = new MainMenu();

	//selection
	Selection* sel = new Selection(mm, scanner);
	mm->setMainScreen(sel);

	//setupSD();

	//setupGPS();
}

void loop() {
	//draw and handel Buttons
	mm->run();
}