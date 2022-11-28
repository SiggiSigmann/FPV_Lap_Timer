#include "SPI_RX5808.h"

/**	##################################################
 *  private
 */
//send data via SPI
void SPI_RX5808::sendData(){
	digitalWrite(SSP, LOW);
  	this->myspi->transfer(messange[0]);
  	this->myspi->transfer(messange[1]);
  	this->myspi->transfer(messange[2]);
  	this->myspi->transfer(messange[3]);
  	digitalWrite(SSP, HIGH);
}

//address part are the first 4 Bits in Message
void SPI_RX5808::setAddress(short address){
	messange[0] = (messange[0] & 0xC0) | (address & 0x2F);
}

//Bit 5 in message is r/w control
void SPI_RX5808::setRW(boolean rw){
	messange[0] = (messange[0] & 0xEF) | (rw << 4);
}

//Bit 8-27 are Data
void SPI_RX5808::setPayload(long payload){
	messange[0] = (messange[0] & 0x1F) | (payload & 0x7)<<5;
	payload = payload >> 3;
	messange[1] = payload & 0xFF;
	payload = payload >> 8;
	messange[2] = payload & 0xFF;
	payload = payload >> 8;
	messange[3] = payload & 0x1F;
}


/**	##################################################
 *  public
 */
//start SPI and set Reag A to 8 => defaultmultiplyer
SPI_RX5808::SPI_RX5808(int rssiPin){
	//create Array for data
	messange = new byte[4];

	this->rssiPin = rssiPin;

	pinMode(SSP, OUTPUT);

	//create MySPI so every Pin can be used
	//I had problem while Using I2C and SPI from Arduino Together.
	//It wil work with this class
	//pin defined in spi_pin.h
	this->myspi = new MySPI();
	this->myspi->begin();

	//set register a to 8 (sould be defoult value)
	setAddress(0);
	setRW(true);
	setPayload(0x8);
	sendData();
}

SPI_RX5808::~SPI_RX5808(){
	delete this->messange;
	delete this->myspi;
}

//set RX to frequenzy in MHz
void SPI_RX5808::setFreq(int freq){
	if(currentChannel == freq) return;

	currentChannel = freq;
	
	setAddress(1);
	setRW(true);
	//freq = flo + 479
	//flo = 2*(N*32+A)*(8HMz/R)
	//R containd in RegA
	//		default = 8 => (8HMz/8) = 1MHz
	//N containd in RegB
	//A containd in RegB
	//=>flo = 2*(N*32+A)

	int flo = freq - 479;	//calc flo
	flo /= 2;				//fomular is now flo*2 = (N*32+A)

	int n = flo >> 5;
	int a = flo & 0x1F;		// 1F = 11111 => 2^5 = 32 = 0x1F

	setPayload((n<<7) | a);


	sendData();
	timeSinceChannel = millis();
}

//get analog value from RSSI Pin
int SPI_RX5808::getRSSI(){
	return analogRead(rssiPin);
}

//get 0 if analogvalue is not valid
int SPI_RX5808::getValideRSSI(){
	if(isRSSIValid()){
		return getRSSI();
	}else{
		return 0;
	}
}

//check if rssi is valid
boolean SPI_RX5808::isRSSIValid(){
	return (timeSinceChannel + valideTime) < millis();
}

unsigned long SPI_RX5808::getValideTime(){
	return valideTime;
}

void SPI_RX5808::setValideTime(unsigned long time){
	valideTime = time;
}

//wait till rssi is valid
void SPI_RX5808::waitTillValid(){
	while(!isRSSIValid()){
		delay(1);
	}
}



