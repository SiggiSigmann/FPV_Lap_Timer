#ifndef SDCARD_H
#define SDCARD_H

#include "FS.h"
#include "SD.h"
#include "SPI.h"

void setupSD();

void listDir(fs::FS &fs, const char * dirname, uint8_t levels);

int getStorageSize();

void deleteAll();
#endif