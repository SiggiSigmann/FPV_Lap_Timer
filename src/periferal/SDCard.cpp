#include "SDCard.h"

SDCard::SDCard(){
  pinMode(SS, OUTPUT);
}


boolean SDCard::sdCardExists(){
  return this->sdCardExistsLastTime;
}

String SDCard::getCardType(){
  return this->cardType; 
}

uint64_t SDCard::getCardSize(){
  return this->cardSize;
}

size_t SDCard::getNumSectors(){
  return this->numSectors;
}

size_t SDCard::getSectorSize(){
  return this->sectorSize;
}

uint64_t SDCard::getTotalBytes(){
  return this->totalBytes;
}

uint64_t SDCard::getUsedBytes(){
  return this->usedBytes;
}

boolean SDCard::initSDCard(){
  sd->end();
  if (!sd->begin(SS)) {
    Serial.println("Card failed, or not present");
    this->cardType = "";
    this->sdCardExistsLastTime = false;
    this->cardSize=0;
		this->numSectors=0;
		this->sectorSize=0;
		this->totalBytes=0;
		this->usedBytes=0;
    return false;
  }
  this->sdCardExistsLastTime = true;
  Serial.println("card initialized.");
  return true;
}

void SDCard::update(){
  if(!this->initSDCard()) return;

  uint8_t cardType = sd->cardType();
  switch (cardType){
    case CARD_NONE:
      this->cardType = "no card";
      break;
    case CARD_MMC:
      this->cardType = "MMC";
      break;
    case CARD_SD:
      this->cardType = "SDSC";
      break;
    case CARD_SDHC:
      this->cardType = "SDHC";
      break;
    default:
      this->cardType = "unknown";
      break;
  }

  this->cardSize = sd->cardSize();
	this->numSectors = sd->numSectors();
	this->sectorSize = sd->sectorSize();
	this->totalBytes = sd->totalBytes()/1000;
	this->usedBytes = sd->usedBytes()/1000;
}


/*void printContentOfFile(){
	 Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  
  
  // see if the card is present and can be initialized:
  this->initSDCard();
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = this->sd->open("/datalog.txt");

  // if the file is available, write to it:
  if (dataFile) {
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  } 
}*/