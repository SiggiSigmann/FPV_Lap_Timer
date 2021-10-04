# SPI
The RX5805 can be controled via SPI. Therefore, two Registers A and B can be used.
To change the values the message format should be used as seen below.
Register A contains a Freuqenzmultiplayer. Regsiter B contains ingormation a and n to
set the frequenzy

RX5805 use the chip RTC6715 => Datasheet: https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&ved=2ahUKEwjMo8viuPHyAhV3_7sIHchcCPYQFnoECAMQAQ&url=https%3A%2F%2Fwww.drohnen-forum.de%2Findex.php%2FAttachment%2F10786-RTC6715-DST-001-PDF%2F&usg=AOvVaw1-naPhXObJroVweQK3Q4Tc

## Message
25 Bits Datastream 
4  Bits Address (0-F)
1  Bit  R/W Control (Write = 1, Read = 0)
20 Bits Data (LSB) (niedrigster Schwellenwert hat stelle 0) -> A0 A1 A2 ...


## REG
Address 0x00: Synthesizer Register A
Address 0x01: Synthesizer Register B
Address 0x02: Synthesizer Register C
Address 0x03: Synthesizer Register D
Address 0x04: VCO Switch-Cap Control Register
Address 0x05: DFC Control Register
Address 0x06: 6M Audio Demodulator Control Register
Address 0x07: 6M5 Audio Demodulator Control Register
Address 0x08: Receiver Control Register 1
Address 0x09: Receiver Control Register 2
Address 0x0A: Power Down Control Register
Address 0x0B~0x0E: Reserved
Address 0x0F: State Register

## Formular
default values:

Reg A => 	R value = 8 (default)
Reg B => 	SYN_RF_A_REG = a = 0 (default)
			SYN_RF_N_REG = n = 8 (default)

F_RF(Frequency) = F_LO + 479

F_LO = 		2(N*32 + A) *(F_OSC/R)
F_OSC =>	Oscialtor(cristal) = shoulb be 8 MHz
			(F_OSC/R) = 8HMZ/8 = 1MHz
F_LO = 		2(N*32 + A) * 1MHz

Exaple with defoult values:
F_LO = 2(8*32 + 0) * 1MHz
F_LO = 512 MHZ
F_RF = 991 MHZ

## SPI INIT
Set default value for reg A:

digitalWrite(SSP, LOW);
SPI.transfer(0x10);
SPI.transfer(0x01);
SPI.transfer(0x00);
SPI.transfer(0x00);
digitalWrite(SSP, HIGH);

0000 0000 0000 0000 0000 0001 0001 0000
extra  |				data    |RW|address|

address = 0000 	=> Reg a
r/w	= 1			=> write
payload	= 1000	=> send 8

=> set multiplayer to 8 => (F_OSC/R) = 8HMZ/8 = 1MHz

## Set Frequenz
digitalWrite(SSP, LOW);
SPI.transfer(0x71);
SPI.transfer(0x20);
SPI.transfer(0x05);
SPI.transfer(0x00);
digitalWrite(SSP, HIGH);

0000 0000 0000 0101 0010 0000 0111 0001
extra  |				data    |RW|address|

address = 0001 	=> Reg b
r/w	= 1			=> write
payload	= 0000 0010 1001 0000 0011	=> n = 82, a = 2
				n		  | a

F_LO = 		2(N*32 + A)	= 5252
F_RF = 		F_LO + 479	= 5731


## TODO
* [ ] Multithreading
* [ ] Trackscanner
* [ ] Trackselection
* [ ] permenent storage of settings
* [ ] delete detected drone
* [ ] add new drone manually
* [ ] websitesupport
* [ ] sound