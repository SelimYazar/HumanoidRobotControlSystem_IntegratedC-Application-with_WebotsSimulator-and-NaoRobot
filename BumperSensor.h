/**
* @file BumperSensor.h
* @Author Hassan Moshtaq (152120181073@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief BumperSensor class to be used in robot applications to get and manage the state of the bumper sensors.
*
* BumperSensor class is used to get and manage the state of the bumper sensors.
* It has bool states and NaoRobotAPI* variable to access the robot API.
* It has getState, updateSensor and checkTouch functions.
*/

#ifndef BUMPSENSOR_H
#define BUMPSENSOR_H

#include "NaoRobotSensorInterface.h"
#include <string>

class BumperSensor : public NaoRobotSensorInterface {
private:
	//! @param states is a bool array to store the state of the bumper sensors.
	bool states[4];

public:
	//! Returns the state of the bumper sensor at the given index.
	bool getState(int index);
	//! Updates the state of the bumper sensors.
	void updateSensor() override;
	//! Checks if any bumper sensor is touched.
	bool checkTouch();
	//! Gets the value of the sensor.
	string getSensorValue() const override;
};

#endif // !BUMPSENSOR_H
