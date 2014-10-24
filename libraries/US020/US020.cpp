#include "Arduino.h"
#include "US020.h"

US020::US020(int echoPin, int trigerPin) {
    pinMode(echoPin, INPUT);
    pinMode(trigerPin, OUTPUT);
    _echoPin = echoPin;
    _trigerPin = trigerPin;
}

unsigned long US020::ping() {
	unsigned long timeEchoUs = 0;
	unsigned long lenMm  = 0;

	digitalWrite(_trigerPin, HIGH);             	//begin to send a high pulse, then US-020 begin to measure the distance
	delayMicroseconds(50);                    		//set this high pulse width as 50us (>10us)
	digitalWrite(_trigerPin, LOW);              	//end this high pulse

	timeEchoUs = pulseIn(_echoPin, HIGH);       	//calculate the pulse width at EchoPin, 
	if((timeEchoUs < 60000) && (timeEchoUs > 1))	//a valid pulse width should be between (1, 60000).
	{
	  lenMm = (timeEchoUs*34/100)/2;      			//calculate the distance by pulse width	  
	  //lenMm = (timeEchoUs * 0.34mm/us) / 2 (mm)
	}
	return lenMm;
}


