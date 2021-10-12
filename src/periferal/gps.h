#ifndef GPSSTUFF_H
#define GPSSTUFF_H

#include <TinyGPS++.h>

#define RXD2 16
#define TXD2 17

void setupGPS();

void updateGPS();


float getLat();


float getLng();


byte getSat();


uint getTime();


uint getDate();


#endif