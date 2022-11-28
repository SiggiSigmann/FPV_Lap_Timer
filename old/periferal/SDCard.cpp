#include "SDCard.h"

SDCard::SDCard(){
  pinMode(SS, OUTPUT);
}

bool SDCard::sdCardExists(){
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

bool SDCard::initSDCard(){
  sd->end();
  if (!sd->begin(SS)) {
    this->cardType = "";
    this->sdCardExistsLastTime = false;
    this->cardSize=0;
		this->numSectors=0;
		this->sectorSize=0;
		this->totalBytes=0;
		this->usedBytes=0;
    currentFile = "";

    return false;
  }
  this->sdCardExistsLastTime = true;
  return true;
}

void SDCard::update(){
  if(!this->initSDCard()){
    toast->setToast("Error");
    return;
  } 

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
  File laps = sd->open("/laps");
  File file = laps.openNextFile();
  this->numberOfLaps = 0;
  while(file){
    if(!file.isDirectory()){
      sd->remove(file.name());
    } 
    file = laps.openNextFile();
  }
  if(!sd->rmdir("/tracks"))  toast->setToast("rm tracks error");

  laps = sd->open("/tracks");
  file = laps.openNextFile();
  this->numberOfLaps = 0;
  while(file){
    if(!file.isDirectory()){
      sd->remove(file.name());
    } 
    file = laps.openNextFile();
  }
  if(!sd->rmdir("/laps"))  toast->setToast("rm laps error");
  if(!sd->remove("/settings"))  toast->setToast("rm settings error");
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

  if(!tracksExists) toast->setToast("tracks folder error");
  if(!lapsExists)  toast->setToast("laps folder error");
  if(!settings)  toast->setToast("settings file error");

  this->isInit = tracksExists & lapsExists & settings;
}

bool SDCard::getInit(){
  return this->isInit;
}

int SDCard::getNumberOfTracks(){
  return numberOfTracks;
}

int SDCard::getNumberOfLaps(){
  return numberOfLaps;
}

String SDCard::getCurrentFile(){
  return currentFile;
}

void SDCard::generateNewFile(){
  File laps = sd->open("/laps");
  File file = laps.openNextFile();
  this->numberOfLaps = 0;
  while(file){
    if(!file.isDirectory()){
      this->numberOfLaps++;
    } 
    file = laps.openNextFile();
  }
  currentFile = "/laps/"+String(this->numberOfLaps)+".txt";

  File newFile = sd->open(currentFile, FILE_WRITE);
  if(!newFile){
    toast->setToast("new File Error");
  }
  newFile.close();
}

void SDCard::appendToNewFile(String message){
  File newFile = sd->open(currentFile, FILE_APPEND);
  newFile.print(message);
  newFile.close();
}

bool SDCard::doesFileExists(String path){
  File file = sd->open(path);
  if(!file){
    file.close();
    return false;
  }
  file.close();
  return true;
}

String SDCard::readFile(String path){
  String content = "";
  File file = sd->open(path);

  Serial.print("Read from file: ");
  while(file.available()){
    content += String((char) file.read());
  }
  file.close();
  return content;
}