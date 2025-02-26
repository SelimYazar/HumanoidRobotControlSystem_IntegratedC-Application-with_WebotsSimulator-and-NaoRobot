/**
* @file RobotControl.h
* @Author Umutcan Cakmak (152120191006@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief RobotControl class to be used in robot applications to control the robot.
* 
* RobotControl class is used to control the robot. It has a position and a connection state.
* It has position, state and connectionState variables.
* The position is a pointer to Pose class to store the position of the robot.
* The state is an integer variable to store the state of the robot.
* The connectionState is an enum variable to store the connection state of the robot.
* It has getPose, print, forward, backward, moveLeft, moveRight, turnLeft, turnRight, stop, getConnectionState and setConnectionState functions.
*/

#ifndef ROBOTCONTROL_H
#define ROBOTCONTROL_H

#include "RobotInterface.h"
#include "NaoRobotInterface.h"
#include "SensorInterface.h"
#include "Pose.h"
#include "Path.h"
#include "Record.h"
#include "RobotOperator.h"
#include <list>

enum Connection {
    NOT_CONNECTED=0, /*!< NOT_CONNECTED is an enum variable to store the connection state of the robot. */
    CONNECTED      /*!< CONNECTED is an enum variable to store the connection state of the robot. */
};

class RobotControl {
private:
    //! @param robotINT is a pointer to NaoRobotInterface class.
    NaoRobotInterface* robotINT;
    //! @param pose is a pointer to Pose class to store the position of the robot.
    Pose pose;
    //! @param path is a pointer to Path class to store the path of the robot.
    Path path;
    //! @param record is a pointer to Record class to store the record of the robot.
    Record* record;
    //! @param robotOperator is a pointer to RobotOperator class to store the operator of the robot.
    RobotOperator robotOperator;
	//! @param sensorList is a list of SensorInterface class.
    list<SensorInterface*> sensorList;
    //! @param connectionState is an enum variable to store the connection state of the robot.
    Connection connectionState;
    //! @param accessGranted is a boolean variable to store the access state of the robot.
    bool accessGranted;

public:
    //! A constructor with parameters.
    RobotControl(NaoRobotInterface* robotINT);
    //! A constructor.
    RobotControl();
    //! A destructor.
    ~RobotControl();
    //! Gets the position of the robot.
    Pose getPose();
    //! Prints the position of the robot.
    void print();
    //! Forward movement of the robot.
    void forward();
    //! Backward movement of the robot.
    void backward();
    //! Left movement of the robot.
    void moveLeft();
    //! Right movement of the robot.
    void moveRight();
    //! Turn left movement of the robot.
    void turnLeft();
    //! Turn right movement of the robot.
    void turnRight();
    //! Stops the robot.
    void stop();
    //! Adds the current pose to the path.
    bool addToPath();
    //! Removes all the poses from the path.
    void clearPath();
    //! Records the path to a file.
    bool recordPathToFile();
    //! Opens access by checking the access code.
    bool openAccess(int accessCode);
    //! Closes access.
    bool closeAccess(int accessCode);
    //! Records sensor data to a file.
    bool recordSensor(const string& type);
    //! Prints sensor data to the console.
    void printSensor(const string& type);
    //! Adds a sensor to the sensorList.
    void addSensor(SensorInterface* sensor);
    //! Gets the connection state of the robot.
    Connection getConnectionState() const;
    //! Sets the connection state of the robot.
    void setConnectionState(Connection state);
    //! Converts pose to string.
    static string poseToString(const Pose& pose);
    //! Sets access granted.
    bool setAccessGranted(bool accessGranted);
};

#endif ROBOTCONTROL_H
