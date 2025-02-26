/**
* @file RobotControlTest.cpp
* @Author Umutcan Cakmak (152120191006@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "RobotControl.h"
#include "NaoRobotAPI.h"
#include "Pose.h"
#include <iostream>
using namespace std;

static void RobotControlTest() {
    cout << "RobotControlTest:" << endl;

    //! Create an instance of NaoRobotAPI.
    NaoRobotAPI* robotAPI = new NaoRobotAPI();

    //! Create an instance of RobotControl.
    RobotControl robot;

    //! Connect the robotAPI.
    robotAPI->connect();

    //! Test getPosition.
    //! @param initialPosition is the initial position of the robot.
    Pose initialPosition = robot.getPose();
    cout << "Initial Position: (" << initialPosition.getX() << ", "
        << initialPosition.getY() << ", " << initialPosition.getTh() << ")\n";

    //! Test connection state.
    robot.setConnectionState(CONNECTED);
    cout << "Connection State: " << robot.getConnectionState() << "\n";

    //! Test movements.
    robot.forward();
    robot.moveLeft();
    robot.turnRight();
    robot.stop();

    //! Print the final position.
    robot.print();

    //! Disconnect the robotAPI.
    robotAPI->disconnect();
}
