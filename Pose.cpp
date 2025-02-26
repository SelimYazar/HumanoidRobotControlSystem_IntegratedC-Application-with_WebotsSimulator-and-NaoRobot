/**
* @file Pose.cpp
* @Author Umutcan Cakmak (152120191006@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "pose.h"
#include <cmath>

Pose::Pose() {}

Pose::~Pose() {}

//! @param x is a double variable to store the x coordinate of the robot.
//! @param y is a double variable to store the y coordinate of the robot.
//! @param th is a double variable to store the angle of the robot.
Pose::Pose(double _x, double _y, double _th) {
    x = _x;
	y = _y;
	th = _th;
}

double Pose::getX() const {
    return x;
}

void Pose::setX(double _x) {
    x = _x;
}

double Pose::getY() const {
    return y;
}

void Pose::setY(double _y) {
    y = _y;
}

double Pose::getTh() const {
    return th;
}

void Pose::setTh(double _th) {
    th = _th;
}

//! @param other is a Pose object to compare with.
bool Pose::operator==(const Pose& other) {
    return (x == other.x && y == other.y && th == other.th);
}

Pose Pose::operator+(const Pose& other) {
    return Pose(x + other.x, y + other.y, th + other.th);
}

Pose Pose::operator-(const Pose& other) {
    return Pose(x - other.x, y - other.y, th - other.th);
}

Pose& Pose::operator+=(const Pose& other) {
    x += other.x;
    y += other.y;
    th += other.th;
    return *this;
}

Pose& Pose::operator-=(const Pose& other) {
    x -= other.x;
    y -= other.y;
    th -= other.th;
    return *this;
}

bool Pose::operator<(const Pose& other) {
    return (x < other.x || (x == other.x && y < other.y) || (x == other.x && y == other.y && th < other.th));
}

void Pose::getPose(double& _x, double& _y, double& _th) {
    _x = x;
    _y = y;
    _th = th;
}

void Pose::setPose(double _x, double _y, double _th) {
    x = _x;
    y = _y;
    th = _th;
}

//! @param pos is a Pose object to find the distance to.
double Pose::findDistanceTo(Pose pos) {
    return sqrt(pow(pos.x - x, 2) + pow(pos.y - y, 2));
}

double Pose::findAngleTo(Pose pos) {
    return atan2(pos.y - y, pos.x - x);
}

//! @param os is a ostream object to print the pose.
//! @param pose is a Pose object to print.
ostream& operator<<(std::ostream& os, const Pose& pose) {
    os << "Pose(X: " << pose.x << ", Y: " << pose.y << ", Th: " << pose.th << ")";
    return os;
}