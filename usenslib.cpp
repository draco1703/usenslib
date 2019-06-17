/*	usens - Library for interfacing with the HC-SR04 Ultrasonic Sensor.
	Created by David M. Nielsen, May 15th, 2019 under the MIT license.
*/

#include "Arduino.h"
#include "usenslib.h"

/* 340 m/s or 0.034 cm/microsecond */
const float speedOfSound = 0.034;
const int averageReadAmount = 10;

Usens::Usens(unsigned char trigPin, unsigned char echoPin){
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	_trigPin = trigPin;
	_echoPin = echoPin;
	
	Serial.println("sensor ready");
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
float Usens::distance(){
	/* clear out trigPin */
	long sum = 0;

	/*averages readings to offset sensor innacuracy*/
	for(int i=0; i < averageReadAmount; i++){
		digitalWrite(_trigPin, LOW);
		delayMicroseconds(10);
		
		digitalWrite(_trigPin, HIGH);
		delayMicroseconds(10);
		digitalWrite(_trigPin, LOW);
	
		sum += pulseIn(_echoPin, HIGH);
	}

	/* distance = timeToObject * speedOfSound*/
	_dist = (sum/averageReadAmount) * speedOfSound / 2;

	return _dist;
}
