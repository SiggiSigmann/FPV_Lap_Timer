#include <Arduino.h>
#include <Wire.h>

//#include "RX5808/SPI_RX5808.h"
#include "menu/MenuFramework.h"
//#include "menu/MenuController.h"
#include "menuStruct/MainMenu.h"

/*#include "menu/utils/Toast.h"
#include "menu/utils/SettingsManager.h"
#include "menu/MainMenu.h"
#include "menu/Windows/Selection.h"

#include "fpv/DroneDetector.h"
#include "fpv/LapTracker.h"
#include "fpv/Scanner.h"
#include "fpv/TrackManager.h"

#include "periferal/tonegenerator.h"

#include "periferal/SDCard.h"
#include "periferal/display.h"*/

#include "periferal/gps.h"
#include "periferal/DHTSensor.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 //MainMenu* mainMenu;

GPS* gps = new GPS();
DHTSensor* dhtSensor = new DHTSensor();

//pereferie
//SPI_RX5808* rx5805 = new SPI_RX5808(34);
/*Tone* toneGenerator;

SDCard* sdCard = new SDCard();
Toast* toast = new Toast();
SettingsManager* settingsManager = new SettingsManager();


//global instances
Scanner* scanner = new Scanner(rx5805);
LapTracker* lapTracker = new LapTracker();
TrackManager* trackManager = new TrackManager();
DroneDetector* droneDetector = new DroneDetector();*/


MenuController* menuController;

void setup() {
	Serial.begin(115200);
	while(!Serial){}
	Serial.println("Start");

	Serial2.begin(9600);
	while(!Serial2){}

	if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { 
		ESP.restart();
	}
	display.clearDisplay();
	display.setTextSize(0);
	display.setTextColor(WHITE);
	display.display();

	//create Main Menu
	//mainMenu = new MainMenu();

	//Define first page
	//Selection* sel = new Selection(mainMenu);
	//mainMenu->setMainScreen(sel);
	menuController = new MenuController(new MainMenu());
	
	//create Tone generator for Beeping
	//toneGenerator = new Tone();
}

void loop() {
	//mainMenu->run();		//draw and handel Buttons
	//toneGenerator->stop();	//stop playing any tones
	//gps->update();			//update to avoid clitching
	menuController->run();		//draw and handel Buttons
}
