/**
* @file SonarSensor.cpp
* @Author Selim Can Yazar (152120191023@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "SonarSensor.h"
#include <iostream>

//! @param index is an integer variable to store the index of the sonar sensor.
double SonarSensor::getRange(int index) {
    return ranges[index];
}

//! @param maxIndex is an integer variable to store the index of the maximum distance.
//! @param maxDistance is a double variable to store the maximum distance.
double SonarSensor::getMax(int& maxIndex) {
    double maxDistance = ranges[0];
    maxIndex = 0;

    for (int i = 1; i < 2; ++i) {
        if (ranges[i] > maxDistance) {
            maxDistance = ranges[i];
            maxIndex = i;
        }
    }
    return maxDistance;
}

//! @param minIndex is an integer variable to store the index of the minimum distance.
//! @param minDistance is a double variable to store the minimum distance.
double SonarSensor::getMin(int& minIndex) {
    double minDistance = ranges[0];
    minIndex = 0;

    for (int i = 1; i < 2; ++i) {
        if (ranges[i] < minDistance) {
            minDistance = ranges[i];
            minIndex = i;
        }
    }
    return minDistance;
}

//! @param left is a double variable to store the range of the left sonar sensor.
//! @param right is a double variable to store the range of the right sonar sensor.
void SonarSensor::updateSensor() {
    double left;
    double right;
    robotAPI->getSonarRange(left, right);
    ranges[0] = left;
    ranges[1] = right;
}

double SonarSensor::operator[](int i) {
    return ranges[i];
}

string SonarSensor::getSensorValue() const {
	string sensorValue = "";
    for (int j = 0; j < 2; ++j) {
		sensorValue += to_string(ranges[j]);
		sensorValue += " ";
	}
	return sensorValue;
}
