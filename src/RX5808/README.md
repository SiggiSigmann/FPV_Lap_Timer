# RX5805
This folder contains all files for RX5805 handling.
To adapt the pinout, adjust the definitions in spi_pin.h

RX5805 use the chip RTC6715 [(Datasheet)](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&ved=2ahUKEwjMo8viuPHyAhV3_7sIHchcCPYQFnoECAMQAQ&url=https%3A%2F%2Fwww.drohnen-forum.de%2Findex.php%2FAttachment%2F10786-RTC6715-DST-001-PDF%2F&usg=AOvVaw1-naPhXObJroVweQK3Q4Tc)

## SPI Communication with RX5805
Handled in SPI_RX5805. The class uses mySPI class for SPI communication. This is needed because of interferences with I2C, which is needed for the Diaplay. To control the RX5805 two Registers, A and B, can be used.
To change the values, messages in the format described below should be used.
Register A contains a Freuqenzmultiplayer. Regsiter B contains ingormation a and n to
set the frequenzy

### Message
| Length  | Description |
| ------------- | ------------- |
| 25 Bits | Datastream |
| 4  Bits | Address (0-F) |
| 1  Bit  | R/W Control (Write = 1, Read = 0) |
| 20 Bits | Data (LSB) (niedrigster Schwellenwert hat stelle 0) -> A0 A1 A2 ... |

#### Address register tabel
| Address  | Register |
| ------------- | ------------- |
| Address 0x00 | Synthesizer Register A |
| Address 0x01 | Synthesizer Register B |
| Address 0x02 | Synthesizer Register C |
| Address 0x03 | Synthesizer Register D |
| Address 0x04 | VCO Switch-Cap Control Register |
| Address 0x05 | DFC Control Register |
| Address 0x06 | 6M Audio Demodulator Control Register |
| Address 0x07 | 6M5 Audio Demodulator Control Register |
| Address 0x08 | Receiver Control Register 1 |
| Address 0x09 | Receiver Control Register 2 |
| Address 0x0A | Power Down Control Register |
| Address 0x0B~0x0E | Reserved |
| Address 0x0F | State Register |

#### Register values
##### Default values

Reg A => 	R value = 8 <br>
Reg B => 	SYN_RF_A_REG = a = 0, SYN_RF_N_REG = n = 8

##### Value Calulation
F_RF(Frequency) = F_LO + 479<br>
F_LO = 		2(N*32 + A) *(F_OSC/R) <br>
F_OSC =>	Oscialtor(cristal) = shoulb be 8 MHz <br>
			(F_OSC/R) = 8HMZ/8 = 1MHz <br>
F_LO = 		2(N*32 + A) * 1MHz <br>

##### Exaple with defoult values:
F_LO = 2(8*32 + 0) * 1MHz
F_LO = 512 MHZ
F_RF = 991 MHZ

### SPI INIT
Set default value for reg A:

digitalWrite(SSP, LOW);
SPI.transfer(0x10);
SPI.transfer(0x01);
SPI.transfer(0x00);
SPI.transfer(0x00);
digitalWrite(SSP, HIGH);

0000 0000 0000 0000 0000 0001 0001 0000 <br>
extra  |				data    |RW|address|

address = 0000 	=> Reg a<br>
r/w	= 1			=> write<br>
payload	= 1000	=> send 8

=> set multiplayer to 8 => (F_OSC/R) = 8HMZ/8 = 1MHz

### Set Frequenz
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


## Tune Time
30 ms will be needed to adjust th rssi level. Need to wait for this time after channel change to get valid rssi values.
