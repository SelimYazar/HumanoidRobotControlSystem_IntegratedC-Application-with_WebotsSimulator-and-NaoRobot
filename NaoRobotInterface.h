/**
* @file NaoRobotInterface.h
* @Author Gurkan Kayi (152120191092@ogrenci.ogu.edu.tr)
* @date January, 2024
* @brief NaoRobotInterface class to be used in robot applications to control the robot.
* 
* NaoRobotInterface class is used to control the robot.
* It is inherited from RobotInterface class.
* It is an interface class.
* It has functions to move the robot.
*/

#ifndef NAOROBOTINTERFACE_H
#define NAOROBOTINTERFACE_H

#include "RobotInterface.h"
#include "NaoRobotAPI.h"

class NaoRobotInterface : public RobotInterface {
private:
    //! @param robotAPI is a pointer to NaoRobotAPI object.
	NaoRobotAPI* robotAPI;

public:
    //! A constructor with parameter.
    NaoRobotInterface(NaoRobotAPI* api);
    //! A constructor.
    NaoRobotInterface();
    //! A destructor.
    ~NaoRobotInterface();
    //! Gets the position of the robot.
    Pose getPose() override;
    //! Prints the position of the robot.
    void print() override;
    //! Forward movement of the robot.
    void forward() override;
    //! Backward movement of the robot.
    void backward() override;
    //! Left movement of the robot.
    void moveLeft() override;
    //! Right movement of the robot.
    void moveRight() override;
    //! Turn left movement of the robot.
    void turnLeft() override;
    //! Turn right movement of the robot.
    void turnRight() override;
    //! Stops the robot.
    void stop() override;
};

#endif // !NAOROBOTINTERFACE_H
