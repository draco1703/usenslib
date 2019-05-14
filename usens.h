#include "Arduino.h"

/*
	usenslib - Library for interfacing with the HC-SR04 Ultrasonic Sensor.
	Created by David M. Nielsen, May 15th, 2019 under the MIT license.
*/

#ifndef usens_h
#define usens_h

class Usens
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
