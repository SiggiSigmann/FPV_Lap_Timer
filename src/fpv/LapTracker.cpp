#include "LapTracker.h"

void LapTracker::setMeasurements(int* level){
	measurevalues = level;
	short amount = CHANNELAMOUT;
	for(int i = 0; i< amount ;i++){
		int index = i;
		boolean peak = true;

		if(measurevalues[i]<this->strengthoffset) continue;
		
		for(int j = 0; j<scannPM; j++){
			if(--index < 0) break;
			if(measurevalues[i]<measurevalues[index]){
				peak = false;
				break;
			}
		}

		index = i;
		for(int j = 0; j<scannPM; j++){
			if(++index > CHANNELAMOUT-1) break;
			if(measurevalues[i]<measurevalues[index]){
				peak = false;
				break;
			}
		}


		if(peak){
			drones[numberOfDrones] = i;

			i += scannPM-1;
			numberOfDrones++;
			if(numberOfDrones == 10){
				return;
			}
		}
	}
}
short LapTracker::getNumberOfDrones(){
	return numberOfDrones;
}

byte* LapTracker::getDroneFreqs(){
	return drones;
}

void LapTracker::setMaxOffset(int m){
	strengthoffset = m;
}

void LapTracker::reset(){
	numberOfDrones = 0;
}

/*void LapTracker::scannValues(int values[]) {
	int max = 0;
	int freufsdfenze = 0;
	for(int i = 0; i<channelAmount;i++){
		rx->setFreq(pgm_read_word_near(channelFreqTable+i));

		delay(rx->getValideTime());
		long sum = 0;
		for(int j = 0;j<100;j++){
			sum += rx->getRSSI();
			delay(1);
		}
		values[i] = sum/100;
		if(max < values[i]){
			max = values[i];
			freufsdfenze = pgm_read_word_near(channelFreqTable+i);
		}
	}
}

short LapTracker::getNumberOfDrones(){
	this->scannValues(this->startValues);

	for(int i = 0; i<channelAmount;i++){
		startValues[i] -= noise[i];
	}

	short user = 0;

	for(int i = 0; i<channelAmount;i++){
		int index = i;
		boolean peak = true;

		
		if(startValues[pgm_read_word_near(channelList+i)]<this->strengthoffset) continue;
		
		for(int j = 0; j<scannPM; j++){
			if(--index < 0) break;
			if(startValues[pgm_read_word_near(channelList+index)]>startValues[pgm_read_word_near(channelList+i)]){
				peak = false;
				break;
			}
		}

		index = i;
		for(int j = 0; j<scannPM; j++){
			if(++index > channelAmount-1) break;
			if(startValues[pgm_read_word_near(channelList+index)]>startValues[pgm_read_word_near(channelList+i)]){
				peak = false;
				break;
			}
		}

		if(peak){
			
			if(!drones[user]){
				delete drones[user];
			}
			
			
			drones[user] = new Drone(pgm_read_word_near(channelFreqTable+pgm_read_word_near(channelList+i)), noise[pgm_read_word_near(channelList+i)], String(user), startValues[pgm_read_word_near(channelList+i)]);



			i += scannPM-1;
			user++;
			if(user == 10){
				dronelength = user;
				return user;
			}
		}
	}
	dronelength = user;
	return user;
}

LapTracker::LapTracker(SPI_RX5808* rx){
	this->rx=rx;
}

int LapTracker::getDroneLenght(){
	return dronelength;
}

Drone** LapTracker::getDroneArray(){
	return drones;
}

void LapTracker::captureNoice(){
	this->scannValues(this->noise);
}

void LapTracker::scanDrones(){
	for(int i = 0; i<dronelength; i++){
		rx->setFreq(drones[i]->getFreq());
		rx->waitTillValid();
		int rssi = rx->getRSSI();
		drones[i]->addRssi(rssi);
	}
}*/