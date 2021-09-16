#include "Scanner.h"

void FPVScanner::scan(int saveto[]){
	lastScann = saveto;
	for(int i = 0; i<channelAmount;i++){
		saveto[pgm_read_word_near(channelList+i)] = scanIdx(i);
	}
}

FPVScanner::FPVScanner(SPI_RX5808*rx){
	this->rx = rx;
}

int FPVScanner::scanIdx(short i){
	if(i<0) return -1;
	if(i>=40) return -1;
	rx->setFreq(pgm_read_word_near(channelFreqTable+pgm_read_word_near(channelList+i)));
	rx->waitTillValid();
	int maxval = rx->getRSSI();
	
	if(denoiced){
		int res = maxval - noise[i];
		if(max<res) max=res;
		if(res<0){
			noise[i] = maxval;
		}
		return maxval - noise[i];
	}else{
		if(max<maxval) max=maxval;
		return maxval;
	}
}


int* FPVScanner::getLastScan(){
	return lastScann;
}

int FPVScanner::getMax(){
	return max;
}

void FPVScanner::captureNoise(){
	denoiced = true;
	long total = 0;
	for(int i = 0; i<channelAmount;i++){
		rx->setFreq(pgm_read_word_near(channelFreqTable+i));
		delay(rx->getValideTime());
		long sum = 0;
		for(int j = 0;j<100;j++){
			//Serial.println(i);
			sum += rx->getRSSI();
			delay(1);
		}
		noise[i] = sum/100;
		total += noise[i];
	}
	this->maxNoice = total/channelAmount;
	if(maxNoice>max){
		max = maxNoice;
	}
}

boolean FPVScanner::isDenoiced(){
	return denoiced;
}

void FPVScanner::resetNoise(){
	for(int i = 0; i<channelAmount;i++){
		noise[i] =0;
	}
	denoiced = false;
}

int FPVScanner::getMaxNoice(){
	return maxNoice;
}