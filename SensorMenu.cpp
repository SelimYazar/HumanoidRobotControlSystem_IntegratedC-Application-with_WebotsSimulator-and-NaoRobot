/**
* @file SensorMenu.cpp
* @Author Hassan Moshtaq (152120181073@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "SensorMenu.h"
#include <iostream>
#include <string>
using namespace std;

SensorMenu::SensorMenu() {}

//! @param api NaoRobotAPI object.
SensorMenu::SensorMenu(NaoRobotAPI* api) : robotAPI(api) {}

//! @param control RobotControl object.
SensorMenu::SensorMenu(RobotControl control) : robotControl(control) {}

void SensorMenu::showMenu() {
	do {
		cout << endl;
		cout << "=== Sensor Menu ===\n";
		cout << "1. Display Pose\n";
		cout << "2. Display Sonar Ranges\n";
		cout << "3. Display Foot Force\n";
		cout << "4. Display Foot Bumpers\n";
		cout << "5. Record Sensor\n";
		cout << "6. Print Sensor\n";
		cout << "7. Back to Main Menu\n";
		cout << "Enter your choice: ";
		cin >> sensorChoice;
		handleChoice();
	} while (sensorChoice != 7);
}

void SensorMenu::handleChoice() {
    switch (sensorChoice) {
	case 1:
		cout << "\nPose: (X) " << robotAPI->getX() << " meters, "
			<< "(Y) " << robotAPI->getY() << " meters, "
			<< "(Th) " << robotAPI->getTh() << " degrees\n";
		break;
	case 2:
		double sonarLeft, sonarRight;
		robotAPI->getSonarRange(sonarLeft, sonarRight);
		cout << "\nSonar Ranges: (LEFT) " << sonarLeft
			<< " meters, (RIGHT) " << sonarRight << " meters\n";
		break;
	case 3:
		cout << "\nFoot Force: " << robotAPI->getFootForce() << " kg.f\n";
		break;
	case 4:
		bool leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right;
		robotAPI->getFootBumpers(leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right);
		cout << "\nFoot Bumpers: (LEFT) " << leftFoot_left << ", " << leftFoot_right
			<< " (RIGHT) " << rightFoot_left << ", " << rightFoot_right << "\n";
		break;
	case 5:	{
		string sensorType;
		cout << "\nEnter the sensor type to record: ";
		cin >> sensorType;
		robotControl.recordSensor(sensorType);
		break;
	}
	case 6:	{
		string sensorType;
		cout << "\nEnter the sensor type to print: ";
		cin >> sensorType;
		robotControl.printSensor(sensorType);
		break;
	}
	case 7:
		cout << "\nBack to Main Menu\n";
		break;
	default:
		cout << "\nInvalid choice. Try again.\n";
		break;
	}
}
