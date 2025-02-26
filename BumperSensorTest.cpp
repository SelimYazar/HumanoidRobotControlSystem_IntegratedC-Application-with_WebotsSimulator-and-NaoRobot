/**
* @file BumperSensorTest.cpp
* @Author Hassan Moshtaq (152120181073@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include <iostream>
#include "NaoRobotAPI.h"
#include "BumperSensor.h"
using namespace std;

//! Tests the BumperSensor class.
static void BumperSensorTest() {
    cout << "BumperSensorTest:" << endl;

    //! Create a NaoRobotAPI object.
    NaoRobotAPI robot;

    //! Create a BumperSensor object.
    //! @param robot is a NaoRobotAPI* variable to access the robot API.
    BumperSensor bumperSensor(&robot);

    for (int i = 0; i < 4; ++i) {
        //! Test get state.
        cout << "Sensor " << i << ": " << (bumperSensor.getState(i) ? "Contact" : "No contact") << endl;
    }
    
    //! Test check touch.
    cout << "Any touch detected: " << (bumperSensor.checkTouch() ? "Yes" : "No") << endl;
    cout << endl;
}
