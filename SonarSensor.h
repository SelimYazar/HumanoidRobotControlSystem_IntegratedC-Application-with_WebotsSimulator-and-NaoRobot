/**
* @file SonarSensor.h
* @Author Selim Can Yazar (152120191023@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief SonarSensor class to be used in robot applications to get and manage the state of the sonar sensors.
* 
* SonarSensor class is used to get and manage the state of the sonar sensors.
* It has double ranges and NaoRobotAPI* variable to access the robot API.
* It has getRange, setRange, getMax, getMin, updateSensor and operator[] functions.
*/

#ifndef SONARSENSOR_H
#define SONARSENSOR_H

#include "NaoRobotSensorInterface.h"
#include <string>

class SonarSensor : public NaoRobotSensorInterface {
private:
	//! @param ranges is a double array to store the range of the sonar sensors.
	double ranges[2];
	 
public:
	//! Returns the range of the sonar sensor at the given index.
	double getRange(int index);
	//! Returns the maximum range of the sonar sensors.
	double getMax(int& index);
	//! Returns the minimum range of the sonar sensors.
	double getMin(int& index);
	//! Updates the range of the sonar sensors.
	void updateSensor() override;
	//! Checks if any sonar sensor is touched.
	double operator[](int i);
	//! Gets the value of the sensor.
	string getSensorValue() const override;
};

#endif // !SONARSENSOR_H
