#ifndef channels
#define channels
#include <Arduino.h>

//amounts of cannels
const int channelAmount = 40;

// Channels with their Mhz Values
const int channelFreqTable[] PROGMEM = {
	// Channel 1 - 8
	5865, 5845, 5825, 5805, 5785, 5765, 5745, 5725, // Band A
	5733, 5752, 5771, 5790, 5809, 5828, 5847, 5866, // Band B
	5705, 5685, 5665, 5645, 5885, 5905, 5925, 5945, // Band E
	5740, 5760, 5780, 5800, 5820, 5840, 5860, 5880, // Band F / Airwave
	5658, 5695, 5732, 5769, 5806, 5843, 5880, 5917  // Raceband
};

// All Channels of the above List ordered by Mhz
const int channelList[] PROGMEM  = {
	19, 32, 18, 17, 33, 16, 7, 34, 8, 24, 6, 9, 25, 5, 35, 10, 26, 4, 11, 27, 3, 36, 12, 28, 2, 13, 29, 37, 1, 14, 30, 0, 15, 31, 38, 20, 21, 39, 22, 23
};

// names of the channels in Hex
const int channelNames[] PROGMEM = {
	0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8,
	0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8,
	0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8,
	0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8,
	0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8
};

//use pgm_read_word_near(pointervalue) to get valuse out of PROGMEM arrays
#endif