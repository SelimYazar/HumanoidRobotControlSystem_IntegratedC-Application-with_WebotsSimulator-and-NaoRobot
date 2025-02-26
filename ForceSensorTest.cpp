/**
* @file ForceSensorTest.cpp
* @Author Hassan Moshtaq (152120181073@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "ForceSensor.h"
#include <iostream>
using namespace std;

//! Tests the ForceSensor class.
static void ForceSensorTest() {
    cout << "ForceSensorTest:" << endl;

    //! Create a ForceSensor object.
    ForceSensor robotForceSensor;

    //! Update the force value.
    robotForceSensor.updateSensor(1.0);

    //! Print the force value.
    cout << "Force: " << robotForceSensor.getForce() << endl;

    //! Check if the robot has fallen.
    if (robotForceSensor.CheckFall()) {
        //! The robot has fallen.
        cout << "Test Scenario : The robot has fallen!" << endl;
    }
    else {
        //! The robot is still standing.
        cout << "Test Scenario : The robot is still standing." << endl;
    }
    cout << endl;
}