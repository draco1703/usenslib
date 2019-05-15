/*	usens - Library for interfacing with the HC-SR04 Ultrasonic Sensor.
	Created by David M. Nielsen, May 15th, 2019 under the MIT license.
*/

#include "Arduino.h"
#include "usenslib.h"

const float speedOfSound = 0.034 /* 340 m/s or 0.034 cm/microsecond */

Usens::Usens(unsigned char trigPin, unsigned char echoPin){i
	pinMode(trigPin, OUTPUT);
	pinmode(echoPin, INPUT);
	_trigPin = trigPin;
	_echoPin = echoPin;

	Serial.begin(7200);
}

/* needs testing */
bool Usens::isBlocked(float blockDistance){
	float currDist = distance();

	if(currDist <= blockDistance){
		return true;
	} else {
		return false;
	}
}

/* needs testing */
unsigned float Usens::distance(){
	/* clear out trigPin */
	digitalWrite(_trigPin, LOW);
	delayMicroseconds(2);
	
	digitalWrite(_trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(_trigPin, LOW);

	_dur = pulseIn(_echoPin, HIGH);

	/* distance = timeToObject * speedOfSound*/
	_dist = _dur * speedOfSound / 2;

	return _dist;
}
