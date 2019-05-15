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
		Usens(char trigPin, char echoPin);
		bool isBlocked(float blockDistance);
		float distance();
	private:
		const char _trigPin;
		const char _echoPin;
		long _dur;
		int _dist;
};

#endif
