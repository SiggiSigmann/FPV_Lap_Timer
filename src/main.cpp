#include <Arduino.h>
#include <Wire.h>

#include "RX5808/SPI_RX5808.h"

#include "menu/MainMenu.h"
#include "menu/Windows/Selection.h"

#include "fpv/DroneDetector.h"
#include "fpv/LapTracker.h"
#include "fpv/Scanner.h"
#include "fpv/TrackManager.h"

#include "periferal/tonegenerator.h"
#include "periferal/gps.h"
#include "periferal/SDCard.h"
#include "periferal/display.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
MainMenu* mainMenu;

//pereferie
SPI_RX5808* rx5805 = new SPI_RX5808(34);
Tone* toneGenerator;
GPS* gps = new GPS();
SDCard* sdCard = new SDCard();

//global instances
Scanner* scanner = new Scanner(rx5805);
LapTracker* lapTracker = new LapTracker();
TrackManager* trackManager = new TrackManager();
DroneDetector* droneDetector = new DroneDetector();

void setup() {
	Serial.begin(115200);
	while(!Serial){}

	Serial2.begin(9600);
	while(!Serial2){}

	if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { 
	Serial.println(F("SSD1306 allocation failed"));
		for(;;); // Don't proceed, loop forever
	}
	display.clearDisplay();
	display.setTextSize(0);
	display.setTextColor(WHITE);
	display.display();

	//create Main Menu
	mainMenu = new MainMenu();

	//Define first page
	Selection* sel = new Selection(mainMenu);
	mainMenu->setMainScreen(sel);
	
	//create Tone generator for Beeping
	toneGenerator = new Tone();
}

void loop() {
	mainMenu->run();		//draw and handel Buttons
	toneGenerator->stop();	//stop playing any tones
	gps->update();			//update to avoid clitching
}
