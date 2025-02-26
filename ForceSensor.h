/**
* @file ForceSensor.h
* @Author Hassan Moshtaq (152120181073@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief ForceSensor class to be used in robot applications to detect the force applied to the robot.
* 
* ForceSensor class is used to detect the force applied to the robot. It has a force value.
*/

#ifndef FORCESENSOR_H
#define FORCESENSOR_H

#include "NaoRobotSensorInterface.h"
#include <string>

class ForceSensor : public NaoRobotSensorInterface {
private:
	//! @param Force is a double variable to store the force applied to the robot.
	double Force;

public:
	//! Updates the force value.
	void updateSensor() override;
	//! Gets the force value.
	double getForce();
	//! Checks if the robot is fallen.
	bool checkFall();
	//! Gets the value of the sensor.
	string getSensorValue() const override;
};

#endif // FORCESENSOR_H
