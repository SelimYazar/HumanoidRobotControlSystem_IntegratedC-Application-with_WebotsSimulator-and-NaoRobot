/**
* @file ConnectionMenu.cpp
* @Author Umutcan Cakmak (152120191006@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "ConnectionMenu.h"
#include <iostream>
using namespace std;

ConnectionMenu::ConnectionMenu() {}

//! @param api NaoRobotAPI object.
//! @param control RobotControl object.
ConnectionMenu::ConnectionMenu(NaoRobotAPI* robotAPI, RobotControl robotControl) : robotAPI(robotAPI), robotControl(robotControl) {}

void ConnectionMenu::showMenu() {
    do {
        cout << endl;
        cout << "=== Connection Menu ===\n";
        cout << "1. Connect Robot\n";
        cout << "2. Disconnect Robot\n";
        cout << "3. Open Access\n";
        cout << "4. Close Access\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> connectionChoice;
        handleChoice();
    } while (connectionChoice != 5);
}

void ConnectionMenu::handleChoice() {
    switch (connectionChoice) {
    case 1:
        if (robotControl.getConnectionState() == NOT_CONNECTED) {
            robotAPI->connect();
            cout << "\nRobot connected.\n";
            robotControl.setConnectionState(CONNECTED);
            break;
        }
        else {
            cout << "\nRobot is already connected. Please disconnect the robot first.\n";
            break;
        }
    case 2:
        if (robotControl.getConnectionState() == CONNECTED) {
            robotAPI->disconnect();
            cout << "\nRobot disconnected.\n";
            robotControl.setConnectionState(NOT_CONNECTED);
            break;
        }
        else {
            cout << "\nRobot is already disconnected. Please connect the robot first.\n";
            break;
        }
    case 3: {
        if (robotControl.getConnectionState() == CONNECTED) {
			int accessCode = 1234;
			cout << "\nEnter access code: ";
			cin >> accessCode;
			robotControl.openAccess(accessCode);
			break;
		}
        else {
			cout << "\nRobot is not connected. Please connect the robot first.\n";
			break;
		}
	}
    case 4: {
        if (robotControl.getConnectionState() == CONNECTED) {
			int accessCode = 1234;
			cout << "\nEnter access code: ";
			cin >> accessCode;
			robotControl.closeAccess(accessCode);
			break;
		}
        else {
			cout << "\nRobot is not connected. Please connect the robot first.\n";
			break;
		}
	}
    case 5:
        cout << "\nBack to Main Menu\n";
        break;
    default:
        cout << "\nInvalid choice. Try again.\n";
        break;
    }
}
