/**
* @file SonarSensorTest.cpp
* @Author Selim Can Yazar (152120191023@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "NaoRobotAPI.h"
#include "SonarSensor.h"
#include <iostream>
using namespace std;

//! Tests the SonarSensor class.
static void SonarSensorTest() {
    cout << "SonarSensorTest:" << endl;

    //! Create a NaoRobotAPI object.
    NaoRobotAPI robot;

    //! Create a SonarSensor object.
    //! @param robot is a NaoRobotAPI* variable to access the robot API.
    SonarSensor sonarSensor(&robot);

    //! Test get range.
    //! @param minIndex is an integer variable to store the index of the minimum distance.
    //! @param maxIndex is an integer variable to store the index of the maximum distance.
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 0; i < 2; ++i) {
        //! Test get range.
        cout << "Range " << i << ": " << sonarSensor.getRange(i) << " meters" << endl;
    }

    //! Update minIndex and maxIndex.
    sonarSensor.getMin(minIndex);
    sonarSensor.getMax(maxIndex);

    //! Test get min and max.
    cout << "Minimum Range: " << sonarSensor.getMin(minIndex) << " meters (Index: " << minIndex << ")" << endl;
    cout << "Maximum Range: " << sonarSensor.getMax(maxIndex) << " meters (Index: " << maxIndex << ")" << endl;
    cout << endl;
}
