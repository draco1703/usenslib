#include "Arduino.h"

/*
	ultrasenslib - Library for interfacing with the HC-SR04 Ultrasonic Sensor.
	Created by David M. Nielsen, May 15th, 2019 under the MIT license.
*/

#ifndef ultrasenslib_h
#define ultrasenslib_h

class Ultrasenslib
{
	public:
		bool isBlocked();
		unsigned float distance();
	private:
		unsigned char _trigPin;
		unsigned char _echoPin;
		unsigned long _dur;
		unsigned int _dist;
}

#endif
