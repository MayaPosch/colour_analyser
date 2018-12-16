# Colour Analyser #

This Colour Analyser project aims to use colour sensors to make it easy to perform certain operations, including:

* Getting the colour code for a material.
* Measuring the lux levels in an area.
* Analysing the efficiency of photosynthesis by plants.

## Status ##

The current firmware assumes the presence of a TCS34725 [1] RGBC colour sensor on the I2C bus. This initial firmware merely reads out the RGB values along with the lux value and writes these to the serial output.

For the next step the processing algorithms will be implemented.

At this point the firmware has been tested on an Arduino Uno-compatible board, but should work with any AVR ATmega-based system.

## Building ##

The Colour Analyser's firmware uses the [Nodate](https://github.com/MayaPosch/Nodate) C++ framework. After installing it per the instructions, simply execute the following in the project's root folder:

`make`

This will compile the code and generate the firmware image in Intel HEX format. By default it uses the Arduino Uno board preset. When using a different board be sure to update the target board in the project's Makefile. 

To write the image to the target board, determine the COM port or device name that the connected board is listed under (e.g. using 'Device Manager' in Windows), then execute the following command:

`make flash COM_PORT=<port/device>`

Assuming that the programmer has been correctly configured, this will write the image and restart the system. One can now connect to the board with a serial terminal application and see the sensor readouts (RGB, Lux).



[1] TCS34725 Color Sensor: [https://ams.com/tcs34725](https://ams.com/tcs34725 "TCS34725 Color Sensor")