/**
* @file RobotControl.cpp
* @Author Umutcan Cakmak (152120191006@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "RobotControl.h"
#include<iostream>
#include<sstream>
using namespace std;

RobotControl::RobotControl(NaoRobotInterface* robotINT) : robotINT(robotINT) {
	record = new Record();
	accessGranted = false;
	connectionState = NOT_CONNECTED;
}

RobotControl::RobotControl() {
	record = new Record();
	accessGranted = false;
	connectionState = NOT_CONNECTED;
}

RobotControl::~RobotControl() {
	delete robotINT;
}

Pose RobotControl::getPose() {
	double x, y, th;
	pose.getPose(x, y, th);
	return Pose(x, y, th);
}

//! @param connectionState is an enum variable to store the connection state of the robot.
Connection RobotControl::getConnectionState() const {
	return connectionState;
}

//! @param state is an enum variable to store the connection state of the robot.
void RobotControl::setConnectionState(Connection state) {
	connectionState = state;
}

void RobotControl::print() {
	robotINT->print();
}

void RobotControl::forward() {
	robotINT->forward();
}

void RobotControl::backward() {
	robotINT->backward();
}

void RobotControl::moveLeft() {
	robotINT->moveLeft();
}

void RobotControl::moveRight() {
	robotINT->moveRight();
}

void RobotControl::turnLeft() {
	robotINT->turnLeft();
}

void RobotControl::turnRight() {
	robotINT->turnRight();
}

void RobotControl::stop() {
	robotINT->stop();
}

//! @param currentPose is a Pose object to store the current pose of the robot.
bool RobotControl::addToPath() {
	if (accessGranted = true) {
		getPose();
		Pose currentPose = getPose();

		cout << "\nPath size before adding: " << path.getSize() << endl;
		path.addPos(currentPose);
		cout << "Path size after adding: " << path.getSize() << endl;
	
		return true;
	}
	else {
		cout << "Error: Access not granted. Cannot add to path.\n";
		return false;
	}
}

void RobotControl::clearPath() {
	if (accessGranted = true) {
		cout << "\nPath size before clear: " << path.getSize() << endl;
		while (path.getSize() > 0) {
			path.removePos(0);
		}
		cout << "Path size after clear: " << path.getSize() << endl;
	}
	else {
		cout << "Error: Access not granted. Cannot clear path.\n";
	}
}

//! @param fileName is a string variable to store the name of the file to read from.
//! @param pathCopy is a Path object to store the path read from the file.
bool RobotControl::recordPathToFile() {
	if (accessGranted = true) {
		string fileName;
		cout << "\nEnter the file name to write to: ";
		cin >> fileName;

		record->setFileName(fileName);

		if (record->openFile()) {
			Path pathCopy = path;
			for (int i = 0; i < pathCopy.getSize(); ++i) {
				Pose currentPose = pathCopy.getPos(i);
				record->operator<<(poseToString(currentPose));
			}

			// Close the file after writing.
			record->closeFile();
			cout << "\nPath recorded to file successfully.\n";
			return true;
		}
		else {
			cout << "Error: Unable to open the file.\n";
			return false;
		}
	}
	else {
		cout << "Error: Access not granted. Cannot record path.\n";
		return false;
	}
}

bool RobotControl::openAccess(int accessCode) {
	accessGranted = true;
	setAccessGranted(accessGranted);
	cout << "Access granted.\n";
	return true;
}

bool RobotControl::closeAccess(int accessCode) {
	accessGranted = false;
	setAccessGranted(accessGranted);
	cout << "Access closed.\n";
	return true;
}

bool RobotControl::recordSensor(const string& type) {
	if (accessGranted = true) {
		for (SensorInterface* sensor : sensorList) {
			if (sensor->getSensorType() == type) {
				record->writeLine(sensor->getSensorValue());
				cout << "Sensor data recorded to file.\n";
				return true;
			}
		}
		cout << "Error: Sensor type not found.\n";
		return false;
	}
	else {
		cout << "Error: Access not granted. Cannot record sensor data.\n";
		return false;
	}
}

void RobotControl::printSensor(const string& type) {
	if (accessGranted = true) {
		for (SensorInterface* sensor : sensorList) {
			if (sensor->getSensorType() == type) {
				cout << "Sensor data: " << sensor->getSensorValue() << endl;
				return;
			}
		}
		cout << "Error: Sensor type not found.\n";
	}
	else {
		cout << "Error: Access not granted. Cannot print sensor data.\n";
	}
}

void RobotControl::addSensor(SensorInterface* sensor) {
	if (accessGranted = true) {
		sensorList.push_back(sensor);
		cout << "Sensor added.\n";
	}
	else {
		cout << "Error: Access not granted. Cannot add sensor.\n";
	}
}

//! @param oss is an ostringstream object to store the pose as a string.
string RobotControl::poseToString(const Pose& pose) {
	ostringstream oss;
	oss << pose.getX() << " " << pose.getY() << " " << pose.getTh();
	return oss.str();
}

bool RobotControl::setAccessGranted(bool accessGranted) {
	return this->accessGranted = accessGranted;
}
