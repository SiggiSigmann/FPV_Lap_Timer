#include <Arduino.h>

#include <Wire.h>

#include "RX5808/SPI_RX5808.h"

#include "menu/MainMenu.h"
#include "menu/Windows/Selection.h"

#include "periferal/display.h"

#include "fpv/DroneDetector.h"
#include "fpv/LapTracker.h"
#include "fpv/Scanner.h"
#include "fpv/TrackManager.h"

#include "periferal/tonegenerator.h"
#include "periferal/I2c/Communication.h"
#include "periferal/gps.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

MainMenu* mm;

//setup receiver
SPI_RX5808* rx = new SPI_RX5808(34);

//global instances
Scanner* scanner = new Scanner(rx);
LapTracker* lapTracker = new LapTracker();
TrackManager* trackManager = new TrackManager();
DroneDetector* droneDetector = new DroneDetector();

//tones
Tone* toneGenerator;

SerialCommunication* communication = new SerialCommunication();
GPS* gps = new GPS();

void setup() {
	Serial.begin(115200);
	while(!Serial){}

	Serial2.begin(9600);

	if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { 
	Serial.println(F("SSD1306 allocation failed"));
		for(;;); // Don't proceed, loop forever
	}
	display.clearDisplay();
	display.setTextSize(0);
	display.setTextColor(WHITE);
	display.display();

	//main Menu
	mm = new MainMenu();

	//selection
	Selection* sel = new Selection(mm);
	mm->setMainScreen(sel);

	//setupSD();

	//setupGPS();

	toneGenerator = new Tone();
}

void loop() {
	//draw and handel Buttons
	mm->run();
	toneGenerator->stop();
}