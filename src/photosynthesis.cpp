// Basic Blinky example for Nodate framework.
// This uses the same API calls as with the Arduino framework.

#include <wiring.h>
#include <HardwareSerial.h>
#include "Adafruit_TCS34725.h"


int main () {
	// Initialise.
	init(); // for wiring.h
	initVariant();	
	
	// Start UART.
	Serial.begin(9600);
	
	// Set the pin mode on the built-in LED.
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, LOW);
	
	// Initialise the colour sensor.
	Adafruit_TCS34725 sensor; // TODO: Check integration time & gain.
	if (sensor.begin()) {
		Serial.println("Colour sensor found.");
	}
	else {
		// Error.
		Serial.println("Colour sensor not found.");
		while (1);
	}
	
	while (1) {
		digitalWrite(LED_BUILTIN, HIGH);
		delay(1000);
		digitalWrite(LED_BUILTIN, LOW);
		delay(1000);
		
		// Take reading.
		uint16_t r, g, b, c, colorTemp, lux;
		sensor.getRawData(&r, &g, &b, &c);
		lux = sensor.calculateLux(r, g, b);
		
		// Output lux & RGB values.
		Serial.println("Red: " + String(r));
		Serial.println("Green: " + String(g));
		Serial.println("Blue: " + String(b));
		Serial.println("Lux: " + String(lux));
		
		// Perform calculation.
		// Calibrate with initial RGB values?
		float result = 0.0;
		
		
		// Return result on the UART interface.
		Serial.println(String(result));
		
		if (serialEventRun) { serialEventRun(); } // Run the serial event queue.
	}
	
	return 0;
}
