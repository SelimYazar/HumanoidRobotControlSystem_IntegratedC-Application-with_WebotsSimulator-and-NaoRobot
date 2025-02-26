/**
* @file ForceSensor.cpp
* @Author Hassan Moshtaq (152120181073@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "ForceSensor.h"
#include <iostream>

//'FALL_THRESHOLD' is the threshold value to detect if the robot has fallen.
const double FALL_THRESHOLD = 0.5;

void ForceSensor::updateSensor() {
    /*double newForce = 0;
    newForce = robotAPI->getFootForce();
    Force = newForce;*/
}

double ForceSensor::getForce() {
    return Force;
}

bool ForceSensor::checkFall() {
    if (Force < FALL_THRESHOLD) {
        return true;
    }
    else {
        return false;
    }
}

string ForceSensor::getSensorValue() const {
	return to_string(Force);
}
