/**
* @file NaoRobotSensorInterface.h
* @Author Hassan Moshtaq (152120181073@ogrenci.ogu.edu.tr)
* @Author Selim Can Yazar (152120191023@ogrenci.ogu.edu.tr)
* @date January, 2024
* @brief NaoRobotSensorInterface class to be used in robot applications to get and manage the state of the sensors.
* 
* NaoRobotSensorInterface class is used to get and manage the state of the sensors.
* It is inherited from SensorInterface class.
*/

#ifndef NAOROBOTSENSORINTERFACE_H
#define NAOROBOTSENSORINTERFACE_H

#include "SensorInterface.h"
#include "NaoRobotAPI.h"

class NaoRobotSensorInterface : public SensorInterface {
protected:
	//! @param robotAPI is a pointer to NaoRobotAPI object.
	NaoRobotAPI* robotAPI;
};

#endif // !NAOROBOTSENSORINTERFACE_H
