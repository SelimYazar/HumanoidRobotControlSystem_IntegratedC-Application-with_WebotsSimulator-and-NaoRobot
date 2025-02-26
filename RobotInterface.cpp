/**
* @file RobotInterface.cpp
* @Author Umutcan Cakmak (152120191006@ogrenci.ogu.edu.tr)
* @date January, 2024
*/

#include "RobotInterface.h"
#include <iostream>
using namespace std;

void RobotInterface::addSensor(SensorInterface* sensor) {
	sensorList.push_back(sensor);
}
