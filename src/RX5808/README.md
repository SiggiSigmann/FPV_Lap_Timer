# RX5805
This folder contains all files for RX5805 handling.
To adapt the pinout, adjust the definitions in spi_pin.h

## SPI Communication with RX5805
Handled in SPI_RX5805. The class uses mySPI class for SPI. This is needed because of interferences with I2C which is needed for the Diaplay

## Tune Time
30 ms will be needed to adjust th rssi level. Need to wait for this time after channel change to get valid rssi values.


