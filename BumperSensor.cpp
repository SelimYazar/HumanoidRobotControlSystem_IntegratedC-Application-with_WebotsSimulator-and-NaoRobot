/**
* @file BumperSensor.cpp
* @Author Hassan Moshtaq (152120181073@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "BumperSensor.h"

//! @param index is an integer variable to store the index of the bumper sensor.
bool BumperSensor::getState(int index) {
    if (index >= 0 && index < 4) {
        return states[index];
    }
    else {
        return false;
    }
}

//! @param leftfoot_left is a bool variable to store the state of the left bumper sensor on the left foot.
//! @param leftfoot_right is a bool variable to store the state of the right bumper sensor on the left foot.
//! @param rightfoot_left is a bool variable to store the state of the left bumper sensor on the right foot.
//! @param rightfoot_right is a bool variable to store the state of the right bumper sensor on the right foot.
void BumperSensor::updateSensor() {
    bool leftfoot_left;
    bool leftfoot_right;
    bool rightfoot_left;
    bool rightfoot_right;
    robotAPI->getFootBumpers(leftfoot_left, leftfoot_right, rightfoot_left, rightfoot_right);
    states[0] = leftfoot_left;
    states[1] = leftfoot_right;
    states[2] = rightfoot_left;
    states[3] = rightfoot_right;
}

bool BumperSensor::checkTouch() {
    for (int j = 0; j < 4; ++j) {
        if (states[j]) {
            return true;
        }
    }
    return false;
}

string BumperSensor::getSensorValue() const {
    string sensorValue = "";
    for (int j = 0; j < 4; ++j) {
        if (states[j]) {
			sensorValue += "1";
		}
        else {
			sensorValue += "0";
		}
	}
	return sensorValue;
}
