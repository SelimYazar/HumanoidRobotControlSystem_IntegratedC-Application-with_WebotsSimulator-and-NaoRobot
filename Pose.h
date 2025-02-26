/**
* @file Pose.h
* @Author Umutcan Cakmak (152120191006@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief Pose class to be used in robot applications to store the position of the robot.
* 
* Pose class is used to store the position of the robot. It has x, y and th variables.
* It has getPose, setPose, getX, setX, getY, setY, getTh, setTh, findDistanceTo, findAngleTo, operator+, operator-, operator+=, operator-=, operator< and operator== functions.
*/

#ifndef POSE_H
#define POSE_H

#include "NaoRobotAPI.h"
#include <iostream>
using namespace std;

class Pose {
private:
    //! @param x is a double variable to store the x coordinate of the robot.
    double x;
    //! @param y is a double variable to store the y coordinate of the robot.
    double y;
    //! @param th is a double variable to store the angle of the robot.
    double th;

public:
    //! A constructor.
    Pose(double _x, double _y, double _th);
    //! A constructor.
    Pose();
    //! A destructor.
    ~Pose();
    //! Gets the x coordinate of the robot.
    double getX() const;
    //! Sets the x coordinate of the robot.
    void setX(double _x);
    //! Gets the y coordinate of the robot.
    double getY() const;
    //! Sets the y coordinate of the robot.
    void setY(double _y);
    //! Gets the angle of the robot.
    double getTh() const;
    //! Sets the angle of the robot.
    void setTh(double _th);
    //! Checks if two poses are equal.
    bool operator==(const Pose& other);
    //! Pose addition.
    Pose operator+(const Pose& other);
    //! Pose subtraction.
    Pose operator-(const Pose& other);
    //! Pose addition by reference.
    Pose& operator+=(const Pose& other);
    //! Pose subtraction by reference.
    Pose& operator-=(const Pose& other);
    //! Checks if the first pose is greater than the second pose.
    bool operator<(const Pose& other);
    //! Gets the pose.
    void getPose(double& _x, double& _y, double& _th);
    //! Sets the pose.
    void setPose(double _x, double _y, double _th);
    //! Finds the distance to the given pose.
    double findDistanceTo(Pose pos);
    //! Finds the angle to the given pose.
    double findAngleTo(Pose pos);
    //! Overloads the << operator to print the pose.
    friend ostream& operator<<(ostream& os, const Pose& pose);
};

#endif POSE_H
