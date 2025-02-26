/**
* @file OperateRobotMenu.cpp
* @Author Selim Can Yazar (152120191023@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "OperateRobotMenu.h"
#include <iostream>
using namespace std;

OperateRobotMenu::OperateRobotMenu() {}

//! @param control is a RobotControl object.
OperateRobotMenu::OperateRobotMenu(NaoRobotInterface* robotINT) : robotINT(robotINT) {}

void OperateRobotMenu::showMenu() {
    do {
        cout << endl;
        cout << "=== Operate Robot Menu ===\n";
        cout << "1. Move Forward\n";
        cout << "2. Move Backward\n";
        cout << "3. Move Left\n";
        cout << "4. Move Right\n";
        cout << "5. Turn Left\n";
        cout << "6. Turn Right\n";
        cout << "7. Stop\n";
        cout << "8. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> robotChoice;
        handleChoice();
    } while (robotChoice != 8);   
}

void OperateRobotMenu::handleChoice() {
    switch (robotChoice) {
    case 1:
        robotINT->forward();
        cout << "\nRobot moved forward.\n";
        break;
    case 2:
        robotINT->backward();
        cout << "\nRobot moved backward.\n";
        break;
    case 3:
        robotINT->moveLeft();
        cout << "\nRobot moved left.\n";
        break;
    case 4:
        robotINT->moveRight();
        cout << "\nRobot moved right.\n";
        break;
    case 5:
        robotINT->turnLeft();
        cout << "\nRobot turned left.\n";
        break;
    case 6:
        robotINT->turnRight();
        cout << "\nRobot turned right.\n";
        break;
    case 7:
        robotINT->stop();
        cout << "\nRobot stopped.\n";
        break;
    case 8:
        cout << "\nBack to Main Menu\n";
        break;
    default:
        cout << "\nInvalid choice. Try again.\n";
        break;
    }
}
