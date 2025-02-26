/**
* @file RobotInterface.h
* @Author Umutcan Cakmak (152120191006@ogrenci.ogu.edu.tr)
* @date January, 2024
* @brief RobotInterface class to be used in robot applications to control the robot.
*
* RobotInterface class is used to control the robot.
* It is an abstract class.
* It has virtual functions to move the robot.
*/

#ifndef ROBOTINTERFACE_H
#define ROBOTINTERFACE_H

#include "Pose.h"
#include "SensorInterface.h"
#include <vector>

class RobotInterface {
private:
	//! @param position is a pointer to Pose object.
	Pose* position;
	//! @param status is an integer variable to store the state of the robot.
	int status;
	//! @param sensorList is a vector of SensorInterface class.
	vector<SensorInterface*> sensorList;

public:
	//! Gets the position of the robot.
	virtual Pose getPose() = 0;
	//! Prints the position of the robot.
	virtual void print() = 0;
	//! Forward movement of the robot.
	virtual void forward() = 0;
	//! Backward movement of the robot.
	virtual void backward() = 0;
	//! Left movement of the robot.
	virtual void moveLeft() = 0;
	//! Right movement of the robot.
	virtual void moveRight() = 0;
	//! Turn left movement of the robot.
	virtual void turnLeft() = 0;
	//! Turn right movement of the robot.
	virtual void turnRight() = 0;
	//! Stops the robot.
	virtual void stop() = 0;
	//! Updates the sensors of the robot.
	//virtual void updateSensors() = 0;
	//! Adds a sensor to the robot.
	void addSensor(SensorInterface* sensor);
};

#endif // !ROBOTINTERFACE_H
