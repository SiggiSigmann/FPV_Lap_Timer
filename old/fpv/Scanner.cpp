#include "Scanner.h"

Scanner::Scanner(SPI_RX5808* rx5805){
	this->rx5805 = rx5805;
}

void Scanner::captureNoise(){
	long sum = 0;
	maxNoise=0;

	//scann
	for(byte i = 0; i < CHANNELAMOUT ;i++){
		rx5805->setFreq(pgm_read_word_near(channelFreqTable+pgm_read_word_near(channelList+i)));
		rx5805->waitTillValid();

		//capture 100 values and calc mean
		long sum = 0;
		for(byte j = 0;j<100;j++){
			sum += rx5805->getRSSI();
			delay(1);
		}
		noise[i] = sum/100;
		sum += noise[i];

		if(maxNoise < noise[i]) maxNoise = noise[i];
	}

	//calc average noice and subtract form max
	sum /= CHANNELAMOUT;
	if(max > sum) max -= sum;

	//check if max is realy max
	//if(maxNoise > max )max = maxNoise;

	denoised = true;
}

void Scanner::resetNoise(){
	for(byte i = 0; i< CHANNELAMOUT ;i++){
		//set all todefault
		noise[i] =0;
	}
	denoised = false;
	maxNoise = 0;
}

boolean Scanner::isDenoise(){
	return denoised;
}

int Scanner::getMaxNoise(){
	return maxNoise;
}

int* Scanner::getNoise(){
	return noise;
}



void Scanner::scan(){
	//scann all
	for(byte i = 0; i< CHANNELAMOUT ;i++){
		measurement[i] = scanIdx(i);
	}
}

int Scanner::scanIdx(byte i){
	//cehck idx
	if(i<0) return -1;
	if(i>=CHANNELAMOUT) return -1;

	//set rx to frequenzy and wait till rssi is valid
	rx5805->setFreq(pgm_read_word_near(channelFreqTable+pgm_read_word_near(channelList+i)));
	rx5805->waitTillValid();

	int rssi = rx5805->getRSSI();
	
	//denoise
	//if not denoiced then noise[i] => 0
	rssi -= noise[i];

	//store rssi
	measurement[i] = rssi;

	if(max < rssi) max=rssi;
	
	return rssi;
}

int Scanner::scanFreq(int freq){
	//search for index in channelFreqTable
	for(byte i=0; i<CHANNELAMOUT;i++){
		if(pgm_read_word_near(channelFreqTable+pgm_read_word_near(channelList+i)) == freq){

			return scanIdx(i);
		}
	}

	return 0;
}

int* Scanner::getLastScan(){
	return measurement;
}

int Scanner::getMax(){
	return max;
}






