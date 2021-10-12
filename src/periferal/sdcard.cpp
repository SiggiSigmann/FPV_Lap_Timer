#include "sdcard.h"

File root;

void setupSD(){
	if(!SD.begin()){
    Serial.println("Card Mount Failed");
    return;
  }
	uint8_t cardType = SD.cardType();

	if(cardType == CARD_NONE){
	Serial.println("No SD card attached");
	return;
	}

	Serial.print("SD Card Type: ");
	if(cardType == CARD_MMC){
	Serial.println("MMC");
	} else if(cardType == CARD_SD){
	Serial.println("SDSC");
	} else if(cardType == CARD_SDHC){
	Serial.println("SDHC");
	} else {
	Serial.println("UNKNOWN");
	}

	uint64_t cardSize = SD.cardSize() / (1024 * 1024);
	Serial.printf("SD Card Size: %lluMB\n", cardSize);

  root = SD.open("/");
}

int getStorageSize(){
  return SD.cardSize() / (1024 * 1024);
}

/*
void listDir(fs::FS &fs, const char * dirname, uint8_t levels){
  Serial.printf("Listing directory: %s\n", dirname);

  File root = fs.open(dirname);
  if(!root){
    Serial.println("Failed to open directory");
    return;
  }
  if(!root.isDirectory()){
    Serial.println("Not a directory");
    return;
  }

  File file = root.openNextFile();
  while(file){
    if(file.isDirectory()){
      Serial.print("  DIR : ");
      Serial.println(file.name());
      if(levels){
        listDir(fs, file.name(), levels -1);
      }
    } else {
      Serial.print("  FILE: ");
      Serial.print(file.name());
      Serial.print("  SIZE: ");
      Serial.println(file.size());
    }
    file = root.openNextFile();
  }
}*/



void deleteAll(){
  while (true) {
    File entry =  root.openNextFile();
    if (! entry) {
      return;
    }
    
    String name = entry.name();

    if(entry.isDirectory()){
      entry.close();
      continue;
    }
    
    Serial.println(name.substring(1));
    SD.remove(name);

  }
}


void initSD(){
  File myFile = SD.open("/info.txt", FILE_WRITE);

  myFile.close();
}

void logSD(int drone ,int time){
  if(!SD.exists("/info.txt")){
    initSD();
  }
   File logFile = SD.open("/info.txt", FILE_WRITE);
  if (logFile)
  {
    logFile.print(drone);
    logFile.print(",");
    logFile.println(time);
    logFile.close();
  }
}

void logStr(String s){
  if(!SD.exists("/info.txt")){
    initSD();
  }
  
  File logFile = SD.open("/info.txt", FILE_APPEND);
  if (logFile){
    logFile.println(s);
    logFile.close();
    logFile.flush();
  }
}