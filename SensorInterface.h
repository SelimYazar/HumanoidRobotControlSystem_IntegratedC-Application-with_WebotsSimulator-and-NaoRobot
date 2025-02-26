/**
* @file SensorInterface.h
* @Author Hassan Moshtaq (152120181073@ogrenci.ogu.edu.tr)
* @Author Selim Can Yazar (152120191023@ogrenci.ogu.edu.tr)
* @date January, 2024
* @brief SensorInterface class to be used in robot applications to get and manage the state of the sensors.
* 
* SensorInterface class is used to get and manage the state of the sensors.
* It is an abstract class.
* It has getSensorType, virtual updateSensor, virtual getSensorValue and virtual destructor functions.
*/

#ifndef SENSORINTERFACE_H
#define SENSORINTERFACE_H

#include <string>
using namespace std;

class SensorInterface {
private:
	//! @param sensorType is a string variable to store the type of the sensor.
	string sensorType;

public:
	//! Updates the sensor.
	virtual void updateSensor() = 0;
	//! Gets the type of the sensor.
	string getSensorType() const;
	//! Gets the value of the sensor.
	virtual string getSensorValue() const = 0;
	//! Virtual destructor.
	virtual ~SensorInterface();
};

#endif // !SENSORINTERFACE_H
