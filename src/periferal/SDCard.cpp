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

  File root = sd->open("/");
  File file = root.openNextFile();
  boolean tracksExists = false;
  boolean lapsExists = false;
  boolean settings = false;
  while(file){
    if(file.isDirectory()){
      if(String(file.name()).equals("tracks")) tracksExists = true;
      if(String(file.name()).equals("laps")) lapsExists = true;
    }else{
      if(String(file.name()).equals("settings")) settings = true;
    }
    file = root.openNextFile();
  }

  this->isInit = tracksExists & lapsExists & settings;

  File tracks = sd->open("/tracks");
  file = tracks.openNextFile();
  this->numberOfTracks = 0;
  while(file){
    if(!file.isDirectory()){
      this->numberOfTracks++;
    } 
    file = tracks.openNextFile();
  }

  File laps = sd->open("/laps");
  file = laps.openNextFile();
  this->numberOfLaps = 0;
  while(file){
    if(!file.isDirectory()){
      this->numberOfLaps++;
    } 
    file = laps.openNextFile();
  }
  
}

void SDCard::clean(){
  sd->rmdir("/tracks");
  sd->rmdir("/laps");
  sd->remove("/settings");
  this->isInit = false;
}

void SDCard::initialize(){
  File root = sd->open("/");
  File file = root.openNextFile();
  boolean tracksExists = false;
  boolean lapsExists = false;
  boolean settings = false;
  while(file){
    if(file.isDirectory()){
      if(String(file.name()).equals("tracks")) tracksExists = true;
      if(String(file.name()).equals("laps")) lapsExists = true;
    }else{
      if(String(file.name()).equals("settings")) settings = true;
    }
    file = root.openNextFile();
  }

  this->isInit = tracksExists & lapsExists & settings;

  if(!tracksExists) tracksExists = sd->mkdir("/tracks");
  if(!lapsExists) lapsExists = sd->mkdir("/laps");
  if(!settings){
    File newFile = sd->open("/settings", FILE_WRITE);
    settings = newFile;
    newFile.close();
  }

  this->isInit = tracksExists & lapsExists;
}

boolean SDCard::getInit(){
  return this->isInit;
}

int SDCard::getNumberOfTracks(){
  return numberOfTracks;
}

int SDCard::getNumberOfLaps(){
  return numberOfLaps;
}