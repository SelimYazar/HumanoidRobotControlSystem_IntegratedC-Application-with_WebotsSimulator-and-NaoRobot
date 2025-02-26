/**
* @file NaoRobotInterface.cpp
* @Author Gurkan Kayi (152120191092@ogrenci.ogu.edu.tr)
* @date January, 2024
*/

#include "NaoRobotInterface.h"
#include<iostream>
using namespace std;

NaoRobotInterface::NaoRobotInterface(NaoRobotAPI* api) : robotAPI(api) {}

NaoRobotInterface::NaoRobotInterface() {
	robotAPI = new NaoRobotAPI();
}

NaoRobotInterface::~NaoRobotInterface() {
	delete robotAPI;
}

Pose NaoRobotInterface::getPose() {
	return Pose();
}

//! Prints the position of the robot.
//! @param sonarLeft is a double variable to store the left sonar range.
//! @param sonarRight is a double variable to store the right sonar range.
//! @param leftFoot_left is a boolean variable to store the left foot bumper value.
//! @param leftFoot_right is a boolean variable to store the right foot bumper value.
//! @param rightFoot_left is a boolean variable to store the left foot bumper value.
//! @param rightFoot_right is a boolean variable to store the right foot bumper value.
void NaoRobotInterface::print() {
	double sonarLeft, sonarRight;
	robotAPI->getSonarRange(sonarLeft, sonarRight);

	bool leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right;
	robotAPI->getFootBumpers(leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right);

	cout << "--------------------SENSOR VALUES-------------------------------------" << endl;
	cout << "POSE         : (X) " << robotAPI->getX() << " meters, "
		<< "(Y) " << robotAPI->getY() << " meters, "
		<< "(Th) " << robotAPI->getTh() << " degrees" << endl << endl;
	cout << "SONAR RANGES : (LEFT) " << sonarLeft
		<< " meters, (RIGHT) " << sonarRight << " meters" << endl << endl;
	cout << "FOOT FORCE   : " << robotAPI->getFootForce() << " kg.f" << endl << endl;
	cout << "FOOT BUMPERS : (LEFT) " << leftFoot_left << " , " << leftFoot_right
		<< " (RIGHT) " << rightFoot_left << " , " << rightFoot_right << endl;
	cout << "----------------------------------------------------------------------" << endl;
}

//! @param FORWARD is an integer constant to store the forward movement value.
void NaoRobotInterface::forward() {
	robotAPI->moveRobot(FORWARD);
	print();
}

//! @param BACKWARD is an integer constant to store the backward movement value.
void NaoRobotInterface::backward() {
	robotAPI->moveRobot(BACKWARD);
	print();
}

//! @param LEFT is an integer constant to store the left movement value.
void NaoRobotInterface::moveLeft() {
	robotAPI->moveRobot(LEFT);
	print();
}

//! @param RIGHT is an integer constant to store the right movement value.
void NaoRobotInterface::moveRight() {
	robotAPI->moveRobot(RIGHT);
	print();
}

void NaoRobotInterface::turnLeft() {
	robotAPI->turnRobot(LEFT);
	print();
}

void NaoRobotInterface::turnRight() {
	robotAPI->turnRobot(RIGHT);
	print();
}

void NaoRobotInterface::stop() {
	robotAPI->stopRobot();
}
