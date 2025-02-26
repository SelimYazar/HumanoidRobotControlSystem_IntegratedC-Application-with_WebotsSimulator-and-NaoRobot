/**
* @file SensorMenu.h
* @Author Hassan Moshtaq (152120181073@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief SensorMenu class to be used in robot applications to control the sensor menu.
*
* SensorMenu class is used to control the sensor menu in robot applications.
* It is derived from Menu class.
* It has a NaoRobotAPI object to control the robot.
* It has a RobotControl object to control the robot.
* It has a Pose object to get the pose of the robot.
* It has a SonarSensor object to get the sonar sensor data.
* It has a ForceSensor object to get the force sensor data.
* It has a integer to get the sensor choice from the user.
*/

#ifndef SENSORMENU_H
#define SENSORMENU_H

#include "Menu.h"
#include "RobotControl.h"
#include "Pose.h"
#include "SonarSensor.h"
#include "ForceSensor.h"
#include <vector>

class SensorMenu : public Menu {
private:
    //! NaoRobotAPI object to control the robot.
    NaoRobotAPI* robotAPI;
    //! RobotControl object to control the robot.
    RobotControl robotControl;
    //! Integer to get the sensor choice from the user.
    int sensorChoice;
    //! Pose object to get the pose of the robot.
    Pose pose;

public:
    //! A constructor.
    SensorMenu();
    //! A constructor with a NaoRobotAPI object parameter.
    SensorMenu(NaoRobotAPI* api);
    //! A constructor with a RobotControl object parameter.
    SensorMenu(RobotControl control);
    //! Shows the sensor menu.
    void showMenu() override;
    //! Handles the sensor menu choice.
    void handleChoice() override;
};

#endif //SENSORMENU_H
